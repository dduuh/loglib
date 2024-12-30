#include "include/loglib.h"

int main()
{
	log_init("test.log");
	log_info("This is test information");
	log_warning("This is test warning");
	log_error("This is test error");
	log_close();
  return 0;
}