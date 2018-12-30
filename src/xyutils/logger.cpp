#include "xyutils/logger.hpp"

int log_level = LOG_DEBUG;

void set_log_level() {
	log_level = LOG_DEBUG;
}
int get_log_level() {
	return log_level;
}

int isloggable() {
	return 0;
}
