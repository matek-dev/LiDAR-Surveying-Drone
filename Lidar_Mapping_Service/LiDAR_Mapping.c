#include <stdio.h>
#include <wiringPi.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

#define INPUT_PIN 2
#define LED_PIN 0

void LiDAR_Mapping();

int main() {
    // Initialize wiringPi
    if (wiringPiSetup() == -1) {
        fprintf(stderr, "Error initializing wiringPi\n");
        return 1;
    }

    pinMode(INPUT_PIN, INPUT);
    pinMode(LED_PIN, OUTPUT); 

    // Signal to let us know program initiated
    digitalWrite(LED_PIN, HIGH);
    delay(1000);
    digitalWrite(LED_PIN, LOW);
    delay(1000);
    digitalWrite(LED_PIN, HIGH);
    delay(1000);
    digitalWrite(LED_PIN, LOW);
    delay(1000);

    while (1){
        if (digitalRead(INPUT_PIN) == HIGH) {
            LiDAR_Mapping();
            delay(3000); // 3 sec delay if necessary
        }
    }
    return 0;
}

void LiDAR_Mapping() {
    printf("Input signal detected! Starting function...\n");
    digitalWrite(LED_PIN, HIGH);

    pid_t pid1 = fork();
    if (pid1 == -1){
        perror("fork 1 failed");
        exit(1);
    }
    else if (pid1 == 0){
        printf("Launching Unilidar...\n");
        execl("/bin/bash", "bin/bash", "-c", "cd /home/matekdev/Documents/Senior_Design_Lidar/unilidar_sdk/unitree_lidar_ros &&"
            "source devel/setup.bash && roslaunch unitree_lidar_ros run_without_rviz.launch",NULL);
        perror("ececl unilidar");
        exit(1);
    }
    else {
        pid_t pid2 = fork();
        if (pid2 == -1){
            perror("fork 2 failed");
            exit(1);
        }
        else if (pid2 == 0) {         
            sleep(5);
            printf("Launching LIOmapping");
            execl("/bin/bash", "bin/bash", "-c", "cd /home/matekdev/Documents/Senior_Design_Lidar/catkin_point_lio_unilidar &&" 
                "source devel/setup.bash && roslaunch point_lio_unilidar mapping_unilidar.launch", NULL);
            perror("ececl liomapping");
            exit(1);
        }
        else {
            sleep(15);
            while(digitalRead(INPUT_PIN) == LOW) { /* mapping, mapping, mapping */ }
            printf("Killing LOImapping...\n");
            kill(pid2, SIGINT);
            printf("Killing Unilidar...\n");
            kill(pid1, SIGINT);
            digitalWrite(LED_PIN, LOW);
        }
    }
}