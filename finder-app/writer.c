#include <syslog.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>




int main(int argc, char *argv[])
{
	
	openlog(NULL, LOG_CONS, LOG_USER);
	
	if (argc != 3){
		syslog(LOG_ERR, "invalid number of arguments %d\n", argc);
		closelog();
		return 1;
	}
	
	int fd = open(argv[1], O_CREAT | O_WRONLY, 0644 );
	if (fd == -1) {
		syslog(LOG_ERR, "Error opening file %s: %s\n", argv[0], strerror ( errno ));
		closelog();
		return 1;
	}

	int byte_write = write(fd, argv[2], strlen(argv[2]));
				
	if (byte_write == -1) {
		syslog(LOG_ERR, "Error writing %s to %s: %s\n", argv[2], argv[1], strerror ( errno ));
		closelog();
		return 1;
	}

	syslog(LOG_DEBUG, "Writing %s to %s\n", argv[2], argv[1]);
	closelog();

	return 0;
}
