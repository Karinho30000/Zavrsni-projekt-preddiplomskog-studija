#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Tokenizer.cpp"


using namespace std;

void TraverseString(string &str, int &Start_Coord, int &End_Coord)
{
    // Find length of given variable
      int n = str.length();
      // Create an empty string
      string word = "";
   
      // Iterate over the string character by character using
      // For loop
      for (int i = 0; i < n; i++) {
   
          if (str[i] == 'D' or str[i] == 'H'){
              word ="";
              
          }
          else if (str[i] == 'M' or str[i] == 'S' ) {
   
              // Print word
              Start_Coord += stoi(word);
              word = "";
          }
          else if (str[i] == 'N'){
              End_Coord = (Start_Coord + stoi(word)+ 1);
              return;
              
          }
   
         
          else {
              word += str[i];
          }
      }
    return;
  }
      

  





int main(){
    cout<<"started script ";
    Tokenizer Read("chr21_AS.sam");
    ofstream MyFile("Mapped.txt");
    while(Read.nextLine()){
        string Read_Name = Read.getToken();
        
        string a2 = Read.getToken();
        
        string Read_Chromosome = Read.getToken();
        
        int Read_SCoord = stoi(Read.getToken());
        Read.getToken();
        int Read_ECoord = 0;
        string Read_details = Read.getToken();
        TraverseString(Read_details, Read_SCoord, Read_ECoord);
        Tokenizer Event("output21.tsv");
        if (a2 =="16" || a2 =="0"){
            while(Event.nextLine()){
                string Event_Chromosome = Event.getToken();
                int  Event_SCoord = stoi(Event.getToken());
                int  Event_ECoord = stoi(Event.getToken());
                if (Event_Chromosome == Read_Chromosome && Event_SCoord == Read_SCoord && Event_ECoord == Read_ECoord){
                   
                    MyFile <<Event_Chromosome<<" "<<Event_SCoord<<" "<<Event_ECoord<<"\n";
                }
            }
        }

    }
    cout<<"done\n";
    MyFile.close();
}
