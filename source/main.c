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
    kExitErrorStd = EXIT_FAILURE,
    kExitErrorGetFlag,
    kExitErrorSocket,
};

void SubcommandChatbox(int argc, char *argv[], int arg_now)
{
    arg_now++;
    if (argc - 1 > arg_now) {
        printf("Chatbox only need one argument, but now has %d\n", argc - arg_now);
        exit(kExitErrorGetFlag);
    }

    char *message = "Hello VRChat OSC(Chatbox)";
    if (arg_now < argc)
        message = argv[arg_now];

    // VRChat chatbox only allow message of less than 144 characters
    int message_len = strlen(message);
    if (message_len > 144) {
        printf("VRChat limited chatbox characters to 144, but the input is %d\n", message_len);
        exit(kExitErrorStd); // TODO add new error type
    }

    // VRChat OSC server socket
    int fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (fd < 0) {
        perror("Socket create error");
        exit(kExitErrorStd);
    }

    struct sockaddr_in des_addr = {0};
    des_addr.sin_family = AF_INET;
    des_addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    des_addr.sin_port = htons(9000);

    char buffer[256] = {0};
    int len = tosc_writeMessage(buffer, sizeof(buffer), "/chatbox/input", "sT", message);

    if (sendto(fd, buffer, len, 0, (struct sockaddr *)&des_addr, sizeof(des_addr)) == -1) {
        perror("Send message error");
        exit(kExitErrorSocket);
    }
    printf("Sended message: \"%s\"\n", message);

    close(fd);

    return;
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("No action selected\n");
        exit(kExitErrorStd);
    }

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "help") == 0) {
            printf("So, hey shell, print a help!\n");
            exit(kExitSuccess);
        } else if (strcmp(argv[i], "chatbox") == 0) {
            SubcommandChatbox(argc, argv, i);
            exit(kExitSuccess);
        } else {
            printf("Unknown subcommand \"%s\"\n", argv[i]);
            exit(kExitErrorGetFlag);
        }
    }

    return kExitSuccess;
}
