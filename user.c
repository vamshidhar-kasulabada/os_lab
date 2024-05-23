#include <pwd.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

int main() {
    struct passwd *ptr;
    int uid = getuid();
    int gid = getgid();

    printf("\nUser ID and Group ID using getuid(), getgid()\n");
    printf("User ID = %d\n", uid);
    printf("Group ID = %d\n", gid);

    printf("\nPassword information using getpwuid()\n");
    ptr = getpwuid(uid);

    printf("Username = %s\n", ptr->pw_name);
    printf("User ID = %d\n", ptr->pw_uid);
    printf("Group ID = %d\n", ptr->pw_gid);
    printf("Home Directory = %s\n", ptr->pw_dir);
    printf("Shell = %s\n", ptr->pw_shell);

    return 0;
}

