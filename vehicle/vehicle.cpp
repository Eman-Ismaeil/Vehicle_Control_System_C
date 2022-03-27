
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ENGINE_TEMP_CONTROLLER 1


struct vehicle { //global structure 
    int vehicle_speed;
    int Room_temp;
    int Engine_temp;
}V1;

typedef enum { //global enum 
    OFF = 0,
    ON = 1
}state;

void receive_input_on(state* AC, state* engine_temp_controller); //if option: "Turn on the vehicle engine" is selected
void receive_input_off(state* AC, state* engine_temp_controller);//if the option: "TURN OFF THE VEHICLE" is selected
void print_fn();
void set_menu();
void display_vehicle_state(state* AC, state* engine_temp_controller);


int main()
{
    char input;
    state AC;
    state engine_temp_controller;

    print_fn();
    fflush(stdout);
    scanf_s(" %c", &input);
    if (input == 'a') {//Turn on Vehicle

        printf("Turn on vehicle engine\n\n");
        receive_input_on(&AC, &engine_temp_controller);
       
        
    }
    if (input == 'b') {
        printf("Turn off vehicle engine\n\n");
        receive_input_off(&AC, &engine_temp_controller); //go to function which deals with turn off vehicle option
        
    }
    if (input == 'c')
        printf("Quit the system");

}


void print_fn() {
    printf("a. Turn on the vehicle engine\n");
    printf("b. Turn off the vehicle engine\n");
    printf("c. Quit the system\n\n");
}

void set_menu() {
    printf("a. Turn off the engine\n");
    printf("b. Set the traffic light color\n");
    printf("c. Set the room temperature (Temperature Sensor)\n");
#if ENGINE_TEMP_CONTROLLER
    printf("d. Set the engine temperature (Engine Temperature Sensor)\n\n");
#endif
}

void display_vehicle_state(state* AC, state* engine_temp_controller) {
  
    char result_AC[4];
    char result_ENGINE[4];

    if (*AC == 0) {
        strcpy_s(result_AC, "OFF");
    }
    else if (*AC == 1)
        strcpy_s(result_AC, "ON");

#if ENGINE_TEMP_CONTROLLER
    if (*engine_temp_controller == 0)
        strcpy_s(result_ENGINE, "OFF");
    else if (*engine_temp_controller == 1)
        strcpy_s(result_ENGINE, "ON");
#endif

    printf("Engine is ON\n");
    printf("AC is %s\n", result_AC);
    printf("Vehicle Speed: %d Km/Hr\n", V1.vehicle_speed);
    printf("Room Temperature: %d°C\n", V1.Room_temp);
#if ENGINE_TEMP_CONTROLLER
    printf("Engine Temperature Controller is %s\n", result_ENGINE);
    printf("Engine Temperature: %d°C\n\n", V1.Engine_temp);
#endif

}

void receive_input_on(state* AC, state* engine_temp_controller) { //turn on vehicle option chosen

    char inp;
    char color;
    float temp;
    set_menu();
    fflush(stdout);
    scanf_s(" %c", &inp);
    if (inp == 'a') {
       receive_input_off(AC, engine_temp_controller); //turn off vehicle option
       
    }
    else if (inp == 'b') { //set traffic light
        printf("Enter the desired colour 'G' for GREEN,'R' for RED, 'O' for YELLOW: ");
        fflush(stdout);
        scanf_s(" %c", &color);
        printf("\n");
        if (color == 'G')
            V1.vehicle_speed = 100;

        else if (color == 'O') 
            V1.vehicle_speed = 30;
        

        else if (color == 'R')
            V1.vehicle_speed = 0;

        receive_input_on(AC, engine_temp_controller); //select option c then or a
    }
    else if (inp == 'c') {
        printf("Enter the required room temp: ");
        fflush(stdout);
        scanf_s(" %f", &temp);
        printf("\n");
        if (temp < 10 || temp>30) {
            *AC = ON;
            V1.Room_temp = 20;
        }
        else {
            *AC = OFF;
            V1.Room_temp = temp;
           
        }
        
        receive_input_on(AC, engine_temp_controller); //select option d to get the whole data or a to turn off the vehicle

    }
#if ENGINE_TEMP_CONTROLLER 
    else if (inp == 'd') { //engine temp data
        printf("Enter the required engine temp: ");
        fflush(stdout);
        scanf_s(" %f", &temp);
        printf("\n");
        if (temp < 100 || temp>150) {
            *engine_temp_controller = ON;
            V1.Engine_temp = 125;
        }
        else {
            *engine_temp_controller = OFF;

            //V1.Engine_temp=temp;
        }

        if (V1.vehicle_speed == 30) { //Finally if speed is set to 30, make these modifications
            *AC = ON;
            V1.Room_temp = V1.Room_temp * ((float)5 / 4) + 1;

            #if ENGINE_TEMP_CONTROLLER
            * engine_temp_controller = ON;
            V1.Engine_temp = V1.Engine_temp * ((float)5 / 4) + 1;
            #endif
        }
        display_vehicle_state(AC, engine_temp_controller);

    }
#endif


}

void receive_input_off(state* AC, state* eng_temp_controller) { //turn off vehicle
    //flag = 0;
    char inp;
    
    print_fn();
    fflush(stdout);
    scanf_s(" %c", &inp);
    if (inp == 'a')
        receive_input_on(AC, eng_temp_controller);

    if (inp == 'b') {
        printf("Turn off vehicle engine\n\n");
        receive_input_off(AC, eng_temp_controller);
       
    }
    if (inp == 'c') {
        printf("Quit the system\n");
        

    }
 



}













