#include "log.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <array>
#include <string>

#include <chrono>
 
typedef struct gel_log_entry {
	gel_uint line;
	char* function;
	char* file;
	char* message;
	gel_uint32 type;
	gel_uint32 group;
	std::chrono::microseconds time;
}gel_log_entry;

template <typename InIt>
bool compare_partial_string(InIt begin, InIt end, const char* other) {
	for (; begin != end && *other != '\0'; ++begin, ++other) {
		if (*begin != *other) {
			return false;
		}
	}

	return (begin == end) == (*other == '\0');
}

const char* gel_trim_source_path(const char* path, const char* root) {
	const char* p = path;

	while (*p != '\0') {
		const char* next_slash = p;
		while (*next_slash != '\0' && *next_slash != '/' && *next_slash != '\\') {
			++next_slash;
		}

		bool is_src = compare_partial_string(p, next_slash, root);
		p = next_slash;

		if (*p != '\0') {
			++p;
		}
		if (is_src) {
			path = p;
		}
	}
	return path;
}

static const char* gel_get_entry_name(gel_uint32 type) {
	switch (type) {
#define LOG(x)    \
        case log_type::x:  \
		return #x;  \
		break; 
		ALL_LOG_NAME()
	default:
		break;
	}
	return "";
}

static const char* gel_get_group_name(gel_uint32 type) {
	switch (type)
	{
#define GRP(x)       \
       case group_type::x:  \
       return #x;    \
       break;
	   ALL_GROUP_NAME()
	default:
		break;
	}
	return "";
}


static std::string gel_format_entry(gel_log_entry* entry) {
	unsigned int time_seconds = static_cast<unsigned int>(entry->time.count() / 1000000);
	unsigned int time_fractional = static_cast<unsigned int>(entry->time.count() % 1000000);

	const char* log_name = gel_get_entry_name(entry->type);
	const char* group_name = gel_get_group_name(entry->group);

	std::array<char, 4 * 1024> buffer;
	snprintf(buffer.data(), buffer.size(), "[%4u.%06u] %s <%s> %s:%s:%u: %s",
		time_seconds,
		time_fractional,
		group_name,
		log_name,
		entry->file,
		entry->function,
		entry->line,
		entry->message
	);
	return std::string(buffer.data());
}


static void gel_print_message(gel_log_entry* entry) {
	std::string message = gel_format_entry(entry) + "\n";
	fputs(message.c_str(), stderr);
}

gel_log_entry* gel_create_entry(gel_uint32 type,gel_uint32 group, const char* file,
	const char* function, gel_uint line,
	const char* format) {

	using std::chrono::duration_cast;
	using std::chrono::steady_clock;

	static steady_clock::time_point time_origin = steady_clock::now();

	gel_log_entry* entry = new gel_log_entry;
	entry->time = duration_cast<std::chrono::microseconds>(steady_clock::now() - time_origin);
	entry->function = (char*)function;
	entry->line = line;
	entry->file = (char*)gel_trim_source_path(file, "src");
	entry->type = type;
	entry->group = group;
	entry->message = (char*)format;

	return entry;
}

void gel_delete_entry(gel_log_entry* entry) {
	delete entry;
}

void gel_log(gel_uint32 type,gel_uint32 group, const char* file,
	const char* function, gel_uint line,
	const char* format, ...) {
	std::array<char, 4 * 1024> buffer;
	va_list args;
	va_start(args, format);
	vsnprintf(buffer.data(), buffer.size(), format, args);
	va_end(args);
	gel_log_entry* entry = gel_create_entry(type, group, file, function, line, _strdup(buffer.data()));

	gel_print_message(entry);

	gel_delete_entry(entry);
}






