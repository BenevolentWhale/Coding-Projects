#include <arduinoFFT.h>
#include <LiquidCrystal.h>
//#define SAMPLES 128             //SAMPLES-pt FFT. Must be a base 2 number. Max 128 for Arduino Uno.
//128 causes problems
#define SAMPLES 64             //SAMPLES-pt FFT. Must be a base 2 number. Max 128 for Arduino Uno.
                               //128 causes memory issues, samples lowered to 64
#define SAMPLING_FREQUENCY 2048 //Ts = Based on Nyquist, must be 2 times the highest expected frequency.
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int buttonOne = 13;
int buttonTwo = 10;
int buttonThree = 9;
int contrast = 0;

arduinoFFT FFT = arduinoFFT();
 
unsigned int samplingPeriod;
unsigned long microSeconds;
 
double vReal[SAMPLES]; //create vector of size SAMPLES to hold real values
double vImag[SAMPLES]; //create vector of size SAMPLES to hold imaginary values

//Octave and Note Matrix, variables for tracking
int note = 0;
int octave = 0;
String noteArray[12] = {"C","C#","D","D#","E","F","F#","G","G#","A","A#","B"};
//Octaves are just 0-8, so an array isn't needed
float frequencyMatrix [12][10] = {
{16.35, 32.70, 65.41, 130.81, 261.63, 523.25, 1046.50, 2093.00, 4186.01},
{17.32, 34.65, 69.30, 138.59, 277.18, 554.37, 1108.73, 2217.46, 4434.92},
{18.35, 36.71, 73.42, 146.83, 293.66, 587.33, 1174.66, 2349.32, 4698.64},
{19.45, 38.89, 77.78, 155.56, 311.13, 622.25, 1244.51, 2489.02, 4978.03},
{20.60, 41.20, 82.41, 164.81, 329,63, 659.26, 1318.51, 2637.02, 5274.01},
{21.83, 43.65, 87.31, 174.61, 349.23, 698.46, 1396.91, 2793.83, 5587.67},
{23.12, 46.25, 92.50, 185.00, 369.99, 739.99, 1479.98, 2959.96, 5919.91},
{24.50, 49.00, 98.00, 196.00, 392.00, 783.99, 1567.98, 3135.96, 6271.93},
{25.96, 51.91, 103.83, 207.65, 415.30, 830.61, 1661.22, 3322.44, 6644.88},
{27.50, 22.00, 110.00, 220.00, 440.00, 880.00, 1760.00, 3520.00, 7040.00},
{29.14, 58.27, 116.54, 233.08, 466.16, 932.33, 1864.66, 3729.31, 7458.62},
{30.87, 61.87, 123.47, 246.94, 493.88, 987.77, 1975.53, 3951.07, 7902.13}

};
 
void setup() 
{
    pinMode(buttonOne, INPUT_PULLUP);
    pinMode(buttonTwo, INPUT_PULLUP);
    pinMode(buttonThree, INPUT_PULLUP);
    Serial.begin(115200); //Baud rate for the Serial Monitor
    samplingPeriod = round(1000000*(1.0/SAMPLING_FREQUENCY)); //Period in microseconds 
    analogWrite(6,contrast);
    lcd.begin(16,2);
}
 
void loop() 
{  
    
   int buttonOneValue = digitalRead(buttonOne);
   int buttonTwoValue = digitalRead(buttonTwo);
   int buttonThreeValue = digitalRead(buttonThree);
   if (buttonOneValue == LOW){
      changeNote();
   } else if(buttonThreeValue == LOW){
      changeOctave();
   }

        checkFrequency();
    
}

void checkFrequency(){
  /*Sample SAMPLES times*/
    for(int i=0; i<SAMPLES; i++)
    {
        microSeconds = micros();    //Returns the number of microseconds since the Arduino board began running the current script. 
     
        vReal[i] = analogRead(0); //Reads the value from analog pin 0 (A0), quantize it and save it as a real term.
        vImag[i] = 0; //Makes imaginary term 0 always

        /*remaining wait time between samples if necessary*/
        while(micros() < (microSeconds + samplingPeriod))
        {
          //do nothing
        }
    }
 
    /*Perform FFT on samples*/
    FFT.Windowing(vReal, SAMPLES, FFT_WIN_TYP_HAMMING, FFT_FORWARD);
    FFT.Compute(vReal, vImag, SAMPLES, FFT_FORWARD);
    FFT.ComplexToMagnitude(vReal, vImag, SAMPLES);

    /*Find peak frequency and print peak*/
    double peak = FFT.MajorPeak(vReal, SAMPLES, SAMPLING_FREQUENCY);
    
    
    //show proximity to correct frequency
    if(peak - frequencyMatrix[note][octave] > 20){lcd.setCursor(0,1);  lcd.print("b<-o--#");
      if(peak - frequencyMatrix[note][octave] < 10){lcd.setCursor(0,1);  lcd.print("b|-o--#");
        if(peak - frequencyMatrix[note][octave] < 5){lcd.setCursor(0,1); lcd.print("b-|o--#");
           if(peak - frequencyMatrix[note][octave] < 1.5){lcd.setCursor(0,1);  lcd.print("b--O--#");
           }
        }
      }
   }

    
    if(peak - frequencyMatrix[note][octave] < -20){lcd.setCursor(0,1);  lcd.print("b--o->#");
      if(peak - frequencyMatrix[note][octave] > -10){lcd.setCursor(0,1);  lcd.print("b--o-|#");
        if(peak - frequencyMatrix[note][octave] > -5){lcd.setCursor(0,1); lcd.print("b--o|-#");
           if(peak - frequencyMatrix[note][octave] > -1.5){lcd.setCursor(0,1);  lcd.print("b--O--#");
           }
        }
      }
   }

    
    //print actual frequency
    lcd.print(" " + String(peak));   
    delay(250);
    
}

void changeNote(){
//Target Frequency
if(note >= 11){note = 0;} else {
      note++;
}
    lcd.setCursor(0,0);
    lcd.print("                ");
    lcd.setCursor(0,0);
    lcd.print(String(noteArray[note]) + String(octave) + "  " + String(frequencyMatrix[note][octave]) + "Hz");
  delay(250);
}

void changeOctave(){
if(octave >= 8){octave = 0;} else {
      octave++;
}
  lcd.setCursor(0,0);
  lcd.print("                ");
  lcd.setCursor(0,0);
  lcd.print(String(noteArray[note]) + String(octave) + "  " + String(frequencyMatrix[note][octave]) + "Hz");
  delay(250);
}
