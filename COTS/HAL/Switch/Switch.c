
 #include "Switch.h"
 #include "GPIO.h"

 
 
 

 
 
 
 
 
  Switch_Return init_Switch(Switch_Config* Switcharr){
	  
	Switch_Return status = Switch_NotOk;
	GPIO_PinConfig cfg;
	u8 i;
	
	for(i=0 ; i<NO_OF_SWITCHS ; i++){
		
		cfg.port = Switcharr[i].port;
		cfg.pin = Switcharr[i].pin;
		cfg.Pin_mode = Switcharr[i].GPIOPin_mode;
		GPIO_initPin(cfg);
	}
	
	status = Switch_Ok;
	return status; 
	  
  }
 
 Switch_Return get_SwitchValue(Switch_Config Switch, Switch_value* value){
	 
	Switch_Return status = Switch_NotOk;
	GPIO_PinValue val;
	static GPIO_PinValue previousVal=0;
	static u8 counter=0;


	GPIO_getPinValue(Switch.port ,Switch.pin ,&val);

	if(val == previousVal){
		counter++;
	}else{
		counter=0;
	}

	if(counter == 5){
		*value = (Switch.SwMode ^ val);
		counter=0;
	}

	previousVal = val;

/*
	GPIO_getPinValue(Switch.port ,Switch.pin ,&val);
	*value = (Switch.SwMode ^ val);
*/
	status = Switch_Ok;
	return status;
 }
 
