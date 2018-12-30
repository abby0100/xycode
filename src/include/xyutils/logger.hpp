#ifndef _XY_LOGGER_
#define _XY_LOGGER_

enum LOG_LEVEL {
	LOG_VERBOSE = 1,
	LOG_DEBUG,
	LOG_INFO,
	LOG_WARNING,
	LOG_ERROR
};

int get_log_level();

#endif
