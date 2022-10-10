


#include<stdio.h>
#define STATE_ON	'a'
#define	STATE_OFF 	'b'
#define STATE_Quit  'c'
#define WITH_ENGINE_TEMP_CONTROLLER 1
void traffic_light(void);
void room_temp(void);
void engine_temp (void);
void requirements(void);

struct car
{
	int speed ;
	int engine_temperture ;
	int room_temperture;
	char traffic_light ;
	char Engine_State;
	int Ac_state ;
	char check ;

#if( WITH_ENGINE_TEMP_CONTROLLER == 1)//Bouns
	char engine_temperture_controller ;
#endif

};

#if WITH_ENGINE_TEMP_CONTROLLER == 1
struct car s1 = {0,90,35,'R',STATE_OFF,0,'a',STATE_OFF};//global variables
#else
struct car s1 = {0,90,35,'R',STATE_OFF,0,'a'};//global variables
#endif


int main(void)
{

	while(1)
	{

		printf(" a.Turn on the vehicle engine\n b.Turn off the vehicle engine\n c. Quit the system\n");
		fflush(stdout);
		printf("please enter your Engine_state :");
		fflush(stdout);
		scanf(" %c",&s1.Engine_State);

		if(s1.Engine_State==STATE_ON)
		{
			printf("Engine_State=STATE_ON\n\n");
			while(s1.Engine_State == STATE_ON)
			{
				printf("a. Turn off the engine\n");
				fflush(stdout);
				printf("b. Set the traffic light color\n");
				fflush(stdout);
				printf("c. Set the room temperature (Temperature Sensor)\n");
				fflush(stdout);
				printf("d. Set the engine temperature (Engine Temperature Sensor)\n");
				fflush(stdout);

				printf("please entre your variable to check:");
				fflush(stdout);
				scanf(" %c",&s1.check) ;
				if(s1.check=='a')
				{
					s1.Engine_State=STATE_OFF ;
                break ;
				}

				else if(s1.check=='b')
				{
					printf("please entre your traffic light : ");
					fflush(stdout);

					scanf(" %c",&s1.traffic_light);
					traffic_light();
				}


				else if(s1.check=='c')
				{
					printf("please entre your room temp : ");
					fflush(stdout);
					scanf("%d",&s1.room_temperture);
					room_temp();

				}


				else if (s1.check=='d')
				{
					printf("please entre your engine temp : ");
					fflush(stdout);
					scanf("%d",&s1.engine_temperture );
					engine_temp();

				}
				//the six requirements to be printed
				requirements();

			}//end of while loop

		}
		else if (s1.Engine_State == STATE_OFF)  //condition for turn off the engine
		{
			printf("Turn off the vehicle engine\n");

		}
		else
		{
			printf("Quit the vehicle engine\n");
			break;
		}
	}

	return 0;
}//end of main function

void traffic_light(void) {

	if(s1.traffic_light=='g')
	{

		s1.speed=100 ;

	}
	else if(s1.traffic_light=='o')
	{

		s1.speed=30 ;
		s1.Ac_state =STATE_ON ;
		s1.room_temperture =s1.room_temperture*(5/4)+1 ;

#if( WITH_ENGINE_TEMP_CONTROLLER == 1)
		s1.engine_temperture_controller =STATE_ON ;
#endif


		s1.engine_temperture=s1.engine_temperture*(5/4)+1 ;
	}

	else if (s1.traffic_light=='r')
	{

		s1.speed=0;
	}

} //end of traffic_light function

void room_temp(void){
	if(s1.room_temperture<10)
	{

		s1.room_temperture=20 ;
		s1.Ac_state=STATE_ON ;
	}
	else if (s1.room_temperture>30)
	{

		s1.room_temperture=20 ;
		s1.Ac_state=STATE_ON ;
	}
	else
	{

		s1.Ac_state =STATE_OFF ;
	}
}//end of fun of room_temp function

void engine_temp(void){
	if(s1.engine_temperture<100)
	{

		s1.engine_temperture=125 ;
#if( WITH_ENGINE_TEMP_CONTROLLER == 1)
		s1.engine_temperture_controller=STATE_ON ;
#endif
	}
	else if (s1.engine_temperture>150)
	{

		s1.engine_temperture=125 ;
#if( WITH_ENGINE_TEMP_CONTROLLER == 1)
		s1.engine_temperture_controller=STATE_ON ;
#endif
	}
	else
	{
#if( WITH_ENGINE_TEMP_CONTROLLER == 1)
		s1.engine_temperture_controller=STATE_OFF ;
#endif
	}
}//end of engine_temp function

void requirements(void){
	if(s1.Engine_State==STATE_ON)
	{
		printf("Engine is ON\n");
	}
	else
	{
		printf("Engine_State==STATE_OFF\n");
	}


	if(s1.Ac_state==STATE_ON)
	{
		printf("AC ==STATE_ON\n");
	}
	else
	{
		printf("AC==STATE_OFF\n");
	}

	printf("vehicle speed = %d \n",s1.speed);

	printf("room temperture = %d \n",s1.room_temperture);

#if( WITH_ENGINE_TEMP_CONTROLLER == 1)
	if(s1.engine_temperture_controller==STATE_ON )

	{
		printf("engine_temp_controller==STATE_ON\n");
	}
	else
	{
		printf("engine_temp_controller==STATE_OFF\n");
	}
#endif
	printf("engine tempe= %d \n",s1.engine_temperture);

}
