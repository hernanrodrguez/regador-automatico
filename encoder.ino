// ADC levels
#define LEVEL_0   adc < 170
#define LEVEL_1   adc > 170 && adc < 511
#define LEVEL_2   adc > 511 && adc < 852
#define LEVEL_3   adc > 852



int ReadADC(){
  return analogRead(ADC);
}

void ME_Encoder(){
  int adc = ReadADC();
  flag_encoder = ENC_STATIC;
  switch(st_encoder){
    case ST_A:
      if(LEVEL_0)
        st_encoder = ST_B;
      else if(LEVEL_3)
        st_encoder = ST_E;
      break;
    case ST_B:
      if(LEVEL_1)
        st_encoder = ST_C;
      else if(LEVEL_0)
        st_encoder = ST_B;
      else
        st_encoder = ST_A;      
      break;
    case ST_C:
      if(LEVEL_3)
        st_encoder = ST_D;
      else if(LEVEL_1)
        st_encoder = ST_C;
      else
        st_encoder = ST_A;
      break;
    case ST_D:
      if(LEVEL_2){
        flag_encoder = ENC_RIGHT;
        st_encoder = ST_A;
      }
      else if(LEVEL_3)
        st_encoder = ST_D;
      else
        st_encoder = ST_A;        
      break;
    case ST_E:
      if(LEVEL_1)
        st_encoder = ST_F;
      else if(LEVEL_3)
        st_encoder = ST_E;
      else
        st_encoder = ST_A;
      break;
    case ST_F:
      if(LEVEL_0)
        st_encoder = ST_G;
      else if(LEVEL_1)
        st_encoder = ST_F;
      else
        st_encoder = ST_A;
      break;
    case ST_G:
      if(LEVEL_2){
        flag_encoder = ENC_LEFT;
        st_encoder = ST_A;
      }
      else if(LEVEL_0)
        st_encoder = ST_G;
      else
        st_encoder = ST_A;
      break;
    default:
      st_encoder = ST_A;
  }
}
