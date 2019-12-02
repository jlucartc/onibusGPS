#include<stdio.h>
#include<stdlib.h>


unsigned char shiftByteLeft(unsigned char byte, int shift){

  if(shift >= 8){
    return byte;
  }else{
    switch(shift){
      
      case 1:{

        return ((byte & 0x7f) << 1);      

      }
      case 2:{

        return ((byte & 0x3f) << 2);

      }
      case 3:{

        return ((byte & 0x1f) << 3);

      }
      case 4:{

        return ((byte & 0x0f) << 4);

      }
      case 5:{

        return ((byte & 0x07) << 5);

      }
      case 6:{

        return ((byte & 0x03) << 6);

      }
      case 7:{
    
        return ((byte & 0x01) << 7);

      }
      case 8:{

        return ((byte & 0x00) << 8);
  
      }   
  
    }


  }

  return byte;

}

unsigned char* encodeCoord(unsigned char msg[],int len){

  unsigned char encodedMsg[len+2];

  for(int i = 0; i < len+2; i++){

    encodedMsg[i] = 0x0;
    
  }

  int shift = 2;

  int i = 0;

  int j = 0;

  int flagSeparador = 0;

  while(i < len){

     unsigned char mask = 0x00;
        
     switch(shift){
        case 2:
            mask = 0xc0;
        case 4:
            mask = 0xf0;
        case 6:
            mask = 0xfc;
    }
    
    switch(msg[i]){

     case '0':
    
        if(i == 0){

           // sinal positivo representado pelo caractere 'P'
           encodedMsg[j] = (0x0f << 2);

           j++;

           unsigned char firstBits = shiftByteLeft(0x34,2) & 0xc0;

           encodedMsg[j-1] = encodedMsg[j-1] + (firstBits >> 6);

           encodedMsg[j] = 0x34 << 4;

           shift = 4;
          
        }else if(flagSeparador == 1){

           unsigned char firstBits = (0x0f << shift) & mask;

           encodedMsg[j-1] = encodedMsg[j-1] + (firstBits >> (8-shift));

           encodedMsg[j] = (0x0f << shift+2);

           if(shift == 6){

              shift = 2;
            
           }else{

              shift = shift + 2;
            
           }

           i--;

           flagSeparador = 0;

        }else{
          
           unsigned char firstBits = (0x34 << shift) & mask;

           encodedMsg[j-1] = encodedMsg[j-1] + (firstBits >> (8-shift));

           encodedMsg[j] = (0x34 << shift+2);

           if(shift == 6){

              shift = 2;
            
           }else{

              shift = shift + 2;
            
           }
          
        }
    
     case '1':
    
        if(i == 0){

           // sinal positivo representado pelo caractere 'P'
           encodedMsg[j] = (0x0f << 2);

           j++;

           unsigned char firstBits = (0x35 << 2) & 0xc0;

           encodedMsg[j-1] = encodedMsg[j-1] + (firstBits >> 6);

           encodedMsg[j] = 0x35 << 4;

           shift = 4;
          
        }else if(flagSeparador == 1){

           unsigned char firstBits = (0x0f << shift) & mask;

           encodedMsg[j-1] = encodedMsg[j-1] + (firstBits >> (8-shift));

           encodedMsg[j] = (0x0f << shift+2);

           if(shift == 6){

              shift = 2;
            
           }else{

              shift = shift + 2;
            
           }

           i--;

           flagSeparador = 0;

        }else{
          
           unsigned char firstBits = (0x35 << shift) & mask;

           encodedMsg[j-1] = encodedMsg[j-1] + (firstBits >> (8-shift));

           encodedMsg[j] = (0x35 << shift+2);

           if(shift == 6){

              shift = 2;
            
           }else{

              shift = shift + 2;
            
           }
          
        }
    
     case '2':
    
        if(i == 0){

           // sinal positivo representado pelo caractere 'P'
           encodedMsg[j] = (0x0f << 2);

           j++;

           unsigned char firstBits = (0x36 << 2) & 0xc0;

           encodedMsg[j-1] = encodedMsg[j-1] + (firstBits >> 6);

           encodedMsg[j] = 0x36 << 4;

           shift = 4;
          
        }else if(flagSeparador == 1){

           unsigned char firstBits = (0x0f << shift) & mask;

           encodedMsg[j-1] = encodedMsg[j-1] + (firstBits >> (8-shift));

           encodedMsg[j] = (0x0f << shift+2);

           if(shift == 6){

              shift = 2;
            
           }else{

              shift = shift + 2;
            
           }

           i--;

           flagSeparador = 0;

        }else{
          
           unsigned char firstBits = (0x36 << shift) & mask;

           encodedMsg[j-1] = encodedMsg[j-1] + (firstBits >> (8-shift));

           encodedMsg[j] = (0x36 << shift+2);

           if(shift == 6){

              shift = 2;
            
           }else{

              shift = shift + 2;
            
           }
          
        }
    
     case '3':
    
        if(i == 0){

           // sinal positivo representado pelo caractere 'P'
           encodedMsg[j] = (0x0f << 2);

           j++;

           unsigned char firstBits = (0x37 << 2) & 0xc0;

           encodedMsg[j-1] = encodedMsg[j-1] + (firstBits >> 6);

           encodedMsg[j] = 0x37 << 4;

           shift = 4;
          
        }else if(flagSeparador == 1){

           unsigned char firstBits = (0x0f << shift) & mask;

           encodedMsg[j-1] = encodedMsg[j-1] + (firstBits >> (8-shift));

           encodedMsg[j] = (0x0f << shift+2);

           if(shift == 6){

              shift = 2;
            
           }else{

              shift = shift + 2;
            
           }

           i--;

           flagSeparador = 0;

        }else{
          
           unsigned char firstBits = (0x37 << shift) & mask;

           encodedMsg[j-1] = encodedMsg[j-1] + (firstBits >> (8-shift));

           encodedMsg[j] = (0x37 << shift+2);

           if(shift == 6){

              shift = 2;
            
           }else{

              shift = shift + 2;
            
           }
          
        }
    
     case '4':
    
        if(i == 0){

           // sinal positivo representado pelo caractere 'P'
           encodedMsg[j] = (0x0f << 2);

           j++;

           unsigned char firstBits = (0x38 << 2) & 0xc0;

           encodedMsg[j-1] = encodedMsg[j-1] + (firstBits >> 6);

           encodedMsg[j] = 0x38 << 4;

           shift = 4;
          
        }else if(flagSeparador == 1){

           unsigned char firstBits = (0x0f << shift) & mask;

           encodedMsg[j-1] = encodedMsg[j-1] + (firstBits >> (8-shift));

           encodedMsg[j] = (0x0f << shift+2);

           if(shift == 6){

              shift = 2;
            
           }else{

              shift = shift + 2;
            
           }

           i--;

           flagSeparador = 0;

        }else{
          
           unsigned char firstBits = (0x38 << shift) & mask;

           encodedMsg[j-1] = encodedMsg[j-1] + (firstBits >> (8-shift));

           encodedMsg[j] = (0x38 << shift+2);

           if(shift == 6){

              shift = 2;
            
           }else{

              shift = shift + 2;
            
           }
          
        }
    
     case '5':
    
        if(i == 0){

           // sinal positivo representado pelo caractere 'P'
           encodedMsg[j] = (0x0f << 2);

           j++;

           unsigned char firstBits = (0x39 << 2) & 0xc0;

           encodedMsg[j-1] = encodedMsg[j-1] + (firstBits >> 6);

           encodedMsg[j] = 0x39 << 4;

           shift = 4;
          
        }else if(flagSeparador == 1){

           unsigned char firstBits = (0x0f << shift) & mask;

           encodedMsg[j-1] = encodedMsg[j-1] + (firstBits >> (8-shift));

           encodedMsg[j] = (0x0f << shift+2);

           if(shift == 6){

              shift = 2;
            
           }else{

              shift = shift + 2;
            
           }

           i--;

           flagSeparador = 0;

        }else{
          
           unsigned char firstBits = (0x39 << shift) & mask;

           encodedMsg[j-1] = encodedMsg[j-1] + (firstBits >> (8-shift));

           encodedMsg[j] = (0x39 << shift+2);

           if(shift == 6){

              shift = 2;
            
           }else{

              shift = shift + 2;
            
           }
          
        }
         
     case '6':
    
        if(i == 0){

           // sinal positivo representado pelo caractere 'P'
           encodedMsg[j] = (0x0f << 2);

           j++;

           unsigned char firstBits = (0x3a << 2) & 0xc0;

           encodedMsg[j-1] = encodedMsg[j-1] + (firstBits >> 6);

           encodedMsg[j] = 0x3a << 4;

           shift = 4;
          
        }else if(flagSeparador == 1){

           unsigned char firstBits = (0x0f << shift) & mask;

           encodedMsg[j-1] = encodedMsg[j-1] + (firstBits >> (8-shift));

           encodedMsg[j] = (0x0f << shift+2);

           if(shift == 6){

              shift = 2;
            
           }else{

              shift = shift + 2;
            
           }

           i--;

           flagSeparador = 0;

        }else{
          
           unsigned char firstBits = (0x3a << shift) & mask;

           encodedMsg[j-1] = encodedMsg[j-1] + (firstBits >> (8-shift));

           encodedMsg[j] = (0x3a << shift+2);

           if(shift == 6){

              shift = 2;
            
           }else{

              shift = shift + 2;
            
           }
          
        }
    
     case '7':
     
        if(i == 0){

           // sinal positivo representado pelo caractere 'P'
           encodedMsg[j] = (0x0f << 2);

           j++;

           unsigned char firstBits = (0x3b << 2) & 0xc0;

           encodedMsg[j-1] = encodedMsg[j-1] + (firstBits >> 6);

           encodedMsg[j] = 0x3b << 4;

           shift = 4;
          
        }else if(flagSeparador == 1){

           unsigned char firstBits = (0x0f << shift) & mask;

           encodedMsg[j-1] = encodedMsg[j-1] + (firstBits >> (8-shift));

           encodedMsg[j] = (0x0f << shift+2);

           if(shift == 6){

              shift = 2;
            
           }else{

              shift = shift + 2;
            
           }

           i--;

           flagSeparador = 0;

        }else{
          
           unsigned char firstBits = (0x3b << shift) & mask;

           encodedMsg[j-1] = encodedMsg[j-1] + (firstBits >> (8-shift));

           encodedMsg[j] = (0x3b << shift+2);

           if(shift == 6){

              shift = 2;
            
           }else{

              shift = shift + 2;
            
           }
          
        }
         
     case '8':
     
        if(i == 0){

           // sinal positivo representado pelo caractere 'P'
           encodedMsg[j] = (0x0f << 2);

           j++;

           unsigned char firstBits = (0x3c << 2) & 0xc0;

           encodedMsg[j-1] = encodedMsg[j-1] + (firstBits >> 6);

           encodedMsg[j] = 0x3c << 4;

           shift = 4;
          
        }else if(flagSeparador == 1){

           unsigned char firstBits = (0x0f << shift) & mask;

           encodedMsg[j-1] = encodedMsg[j-1] + (firstBits >> (8-shift));

           encodedMsg[j] = (0x0f << shift+2);

           if(shift == 6){

              shift = 2;
            
           }else{

              shift = shift + 2;
            
           }

           i--;

           flagSeparador = 0;

        }else{
          
           unsigned char firstBits = (0x3c << shift) & mask;

           encodedMsg[j-1] = encodedMsg[j-1] + (firstBits >> (8-shift));

           encodedMsg[j] = (0x3c << shift+2);

           if(shift == 6){

              shift = 2;
            
           }else{

              shift = shift + 2;
            
           }
          
        }
    
     case '9':
    
        if(i == 0){

           // sinal positivo representado pelo caractere 'P'
           encodedMsg[j] = (0x0f << 2);

           j++;

           unsigned char firstBits = (0x3d << 2) & 0xc0;

           encodedMsg[j-1] = encodedMsg[j-1] + (firstBits >> 6);

           encodedMsg[j] = 0x3d << 4;

           shift = 4;
          
        }else if(flagSeparador == 1){

           unsigned char firstBits = (0x0f << shift) & mask;

           encodedMsg[j-1] = encodedMsg[j-1] + (firstBits >> (8-shift));

           encodedMsg[j] = (0x0f << shift+2);

           if(shift == 6){

              shift = 2;
            
           }else{

              shift = shift + 2;
            
           }

           i--;

           flagSeparador = 0;

        }else{
          
           unsigned char firstBits = (0x3d << shift) & mask;

           encodedMsg[j-1] = encodedMsg[j-1] + (firstBits >> (8-shift));

           encodedMsg[j] = (0x3d << shift+2);

           if(shift == 6){

              shift = 2;
            
           }else{

              shift = shift + 2;
            
           }
          
        }
    
     case '/':{
     
         unsigned char firstBits = (0x3f << shift) & mask;
  
         encodedMsg[j-1] = encodedMsg[j-1] + (firstBits >> (8-shift));
  
         encodedMsg[j] = (0x3f << shift+2);
  
         if(shift == 6){
  
            shift = 2;
          
         }else{
  
            shift = shift + 2;
          
         }

         flagSeparador = 1;
     }
     case '-':{
     
         unsigned char firstBits = (0x0d << shift) & mask;

         encodedMsg[j-1] = encodedMsg[j-1] + (firstBits >> (8-shift));

         encodedMsg[j] = (0x0d << shift+2);

         if(shift == 6){

            shift = 2;
          
         }else{

            shift = shift + 2;
          
         }

         flagSeparador = 0;
     }    
     case '.':{

         unsigned char firstBits = (0x03 << shift) & mask;

         encodedMsg[j-1] = encodedMsg[j-1] + (firstBits >> (8-shift));

         encodedMsg[j] = (0x03 << shift+2);

         if(shift == 6){

            shift = 2;
          
         }else{

            shift = shift + 2;
          
         }
     }
        
    }

    i++;
    j++;
     
  }

  unsigned char trimmedMsg[len+(j-i)];

  for(int k = 0; k < len+(j-i); k++){
      printf("%x\n",encodedMsg[k]);
      trimmedMsg[k] = encodedMsg[k];
  }

  return trimmedMsg;
   
  
}

unsigned char getNFirstBits(unsigned char byte, int n){

	unsigned char b = 0x00;

	for(int i = 1; i <= n; i++){

		switch(i){

			case 1:{
			
				b = b + (byte & 0x01);
			
			}
			case 2:{

				b = b + (byte & 0x02);

			}
			case 3:{

				b = b + (byte & 0x04);

			}
			case 4:{

				b = b + (byte & 0x08);

			}
			case 5:{

				b = b + (byte & 0x10);
			
			}
			case 6:{

				b = b + (byte & 0x20);

			}
			case 7:{

				b = b + (byte & 0x40);

			}
			case 8:{

				b = b + (byte & 0x80);

			}		

		}

	}

	return b;

}


int main(){

	unsigned char table[64][2] = {
	   {'A',0x00},
	   {'B',0x01},
	   {'C',0x02},
	   {'D',0x03},
	   {'E',0x04},
	   {'F',0x05},
	   {'G',0x06},
	   {'H',0x07},
	   {'I',0x08},
	   {'J',0x09},
	   {'K',0x0a},
	   {'L',0x0b},
	   {'M',0x0c},
	   {'N',0x0d},
	   {'O',0x0e},
	   {'P',0x0f},
	   {'Q',0x10},
	   {'R',0x11},
	   {'S',0x12},
	   {'T',0x13},
	   {'U',0x14},
	   {'V',0x15},
	   {'W',0x16},
	   {'X',0x17},
	   {'Y',0x18},
	   {'Z',0x19},
	   {'a',0x1a},
	   {'b',0x1b},
	   {'c',0x1c},
	   {'d',0x1d},
	   {'e',0x1e},
	   {'f',0x1f},
	   {'g',0x20},
	   {'h',0x21},
	   {'i',0x22},
	   {'j',0x23},
	   {'k',0x24},
	   {'l',0x25},
	   {'m',0x26},
	   {'n',0x27},
	   {'o',0x28},
	   {'p',0x29},
	   {'q',0x2a},
	   {'r',0x2b},
	   {'s',0x2c},
	   {'t',0x2d},
	   {'u',0x2e},
	   {'v',0x2f},
	   {'w',0x30},
	   {'x',0x31},
	   {'y',0x32},
	   {'z',0x33},
	   {'0',0x34},
	   {'1',0x35},
	   {'2',0x36},
	   {'3',0x37},
	   {'4',0x38},
	   {'5',0x39},
	   {'6',0x3a},
	   {'7',0x3b},
	   {'8',0x3c},
	   {'9',0x3d},
	   {'+',0x3e},
	   {'/',0x3f}
	};

	unsigned char msg[3] = "130";

	printf("%x %x %x \n",msg[0],msg[1],msg[2]);		

	encodeCoord(msg,3);

}

