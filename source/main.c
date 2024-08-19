#include <error.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "tinyosc/tinyosc.h"
#include <netinet/in.h>
#include <sys/socket.h>

enum ExitCode {
    kExitSuccess = EXIT_SUCCESS,
    kExitStdError = EXIT_FAILURE,
};

int main(int argc, char *argv[])
{
    char *message;
    if (argc >= 2) {
        message = argv[1];
    } else {
        message = "Hello VRChat OSC!!!";
    }

    int fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (fd < 0) {
        perror("Socket create error");
        exit(kExitStdError);
    }

    // connect to VRChat OSC server
    struct sockaddr_in des_addr = {0};
    des_addr.sin_family = AF_INET;
    des_addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    des_addr.sin_port = htons(9000);

    char buffer[1024] = {0};
    int len = tosc_writeMessage(buffer, sizeof(buffer), "/chatbox/input", "sT", message);

    sendto(fd, buffer, len, 0, (struct sockaddr *)&des_addr, sizeof(des_addr));

    close(fd);
}
