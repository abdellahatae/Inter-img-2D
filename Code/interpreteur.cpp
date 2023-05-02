#include <stdio.h>
#include <iostream>
#include <string.h>
#include <fstream>



/////////////////////////
//les unites lexicale
////////////////////////
#define GO 300;
#define GF 301;
#define PO 302;
#define PF 303;
#define AO 304;
#define AF 305;
#define VR 306;
#define PV 307;
#define ID 308;
#define INT 309;
#define LN 310;
#define RE 311;
#define CE 312;
#define CA 313;
#define EL 314;
#define AR 315;
#define TR 316;
////////////////////////
typedef struct point
{
    int x,y; //pt.x et pt.y
}pt;
////////////////////////
using namespace std;
int ln = 1;
string id;
int tk=0;
//int ntk;
string obj;
string objt;
string num;
int nb;
char src;
char s;
FILE *fp;
ofstream outf ("code_cible.cpp");
ifstream inf ("partie_stable.txt");

int lexer(){

   while (s != EOF)
   {   src = s;
         s = fgetc(fp);
        if ( src == '{' || src == '}' ) {
             if (src == '{')
              {
               return GO;
              }else{  
               return GF;
              }
              }
        else if (  src == '['|| src == ']' ) {
             if (src == '[')
             {
                return AO;
             }else{
                return AF;
              }
              
             }
        else if ( src == '(' || src == ')' ) {
             if (src == '(')
             {
                return PO;
             }else{
              return PF;
            }
            
           
            }
        else if ( src == ',' || src == ';' ) {
             if (src == ',')
             {
                return VR;
             }else{
               return PV;           
             }
            } 
        else if(src >= 'a' && src <= 'z'){
            id = src;
            while ((s >= '0' && s <= '9')||(s >= 'a' && s <= 'z'))
            {
               id = id + s;
               s = getc(fp);
            } 
             return ID; 
            }
        else if(src == 'L' || src == 'C' || src == 'R' || src == 'E' || src == 'A' || src == 'K' || src == 'T'){
             obj = src;
             obj = obj + s;
             s=getc(fp);
             if (obj == "Ln")
             {
                return LN;
             }
             else if (obj == "Ce")
             {
                return CE;
             }
             else if (obj == "Ca")
             {
                return CA;
             }
             else if (obj == "Re")
             {
                return RE;
             }
             else if (obj == "El")
             {
                return EL;
             }
             else if (obj == "Ar")
             {
                return AR;
             }
             else if (obj == "Tr")
             {
                return TR;
             }
         }              
          else if(src >= '0' && src <= '9'){
            num = src;
            while (s >= '0' && s <= '9')
            {
               num = num + s;
               s = getc(fp);
            }
             nb = stoi(num);
            return INT; 
         }
           else if (src == '/') {
            if (s == '/') {
                // skip comments
                while (s != 0 && s != '\n') {
                    s=getc(fp);
                }
             } 
           
         }
           else if( src == '\n'){
              ln++;
         }
           else if( src == '\t'){
         }   
           else{
            cerr << "Not define:" << src << "ligne:"<<ln <<endl;
            exit(-1);
         }
   }return 0;
}
void Afficher(int tk){
    printf("\n");
    switch (tk)
    {
        
     case 304:printf("AO [ :%d",tk);break; 
     case 305:printf("AF ] :%d",tk);break;
     case 306:printf("VR , :%d",tk);break;
     case 307:printf("PV ; :%d",tk);break;
     case 308:printf("ID :%d",tk);break;
     case 309:printf("INT :%d",tk);break;
     case 310:printf("LN :%d",tk);break;
     case 311:printf("RE :%d",tk);break;
     case 312:printf("CE  :%d",tk);break;
     case 313:printf("CA :%d",tk);break;
     case 314:printf("EL :%d",tk);break;
     case 315:printf("AR :%d",tk);break;
     case 316:printf("TR :%d",tk);break;
     case 300:printf("GO { :%d",tk);break;
     case 301:printf("GF } :%d",tk);break;
     case 302:printf("PO ( :%d",tk);break;
     case 303:printf("PF ) :%d",tk);break;
     default :
     printf("nb :%d",tk);
    
    }
}

void test(int tkc){
    Afficher(tk);
    cout<<endl;
   if (tk == tkc) {
       
      tk=lexer();
    } else {
      
      cerr << " Token non valide : " << tk <<"- ligne : "<<ln<<"- j'attendre :" << tkc <<endl;
       Afficher(tk);
       Afficher(tkc);
       cout <<endl;
      exit(-1);
    }
}

void init(){
   cout <<"nb="<<nb<<endl;
    outf << nb;
   test(309);//int  
   outf <<",";                   
   test(306);//,  
   cout <<"nb="<<nb<<endl;
   outf << nb; 
   test(309);//int 
                     
   test(303);//)
}

void C(){
     test(304);
     outf << "(";
 if(tk == 302){ //(
     test(302);
     init();
 }else{
        test(308);//ID
      outf << id <<".x";
      outf << ",";
      outf << id <<".y";
 }
    
     test(306);//,
     outf << ",";
     
     test(309);//nb
     outf << nb;
}

void A(){
     test(304);//[
      outf << "(";
   if(tk == 302){ //(
    test(302);
    init();
   }else{
       test(308);//ID
       outf << id <<".x";
       outf << ",";
       outf << id <<".y";
   } 
     
    test(306);//,
    outf<<",";
   if(tk == 302){ //(
    test(302);
    init();   
   }else{
       test(308);//ID
       outf << id <<".x";
       outf << ",";
       outf << id <<".y";
   }    
}
void parser(){
    cout<< "//////////////////////// 1er APPEL/////////////////////" <<endl;
        tk=lexer(); 
       if (tk == 300)
       {
          test (300);
         while (tk!= 301)
         {//ID,LN,RE,CE,CA,EL,AR,TR
            if (tk == 308 || tk == 310 || tk == 311 || tk == 312 || tk == 313 || tk == 314 || tk == 315 || tk == 316)
            {
               switch (tk)
               {///////////////////////////POINT//////////////////////////////
               case 308:
                  cout << "point"<< endl; 
                     outf << "point "; 

                     outf << id ;                                 
                     test(308);
            
                     test(302);
                     outf <<"(";
                     cout <<"nb="<<nb<<endl;
                     outf << nb;
                     test(309);//int
                     outf << ",";                                                                                                                                
                     test(306);//,
                     // fprintf(fw,"%s.y=%d;",id,nb);
                     cout <<"nb="<<nb<<endl;
                     outf <<nb;
                     test(309);//int  
                     outf << ")" ;                                                                                                                             
                     test(303);//)
                     outf << ";";
                     test(307);//;
                     outf << endl;
                  // }
                  break;
                  /////////////////////////////////////LIGNE//////////////////////////////
               case 310:
                  cout << "Ligne"<< endl;
                    outf << "lignes "; 
                  test(310);
                  if (tk == 309)
                  {
                     cout << "ligne "<<nb<<":" <<endl;
                     outf << obj <<nb;
                     objt=obj + num;
                     test(309);
                  } 
               
                      A();

                     test(305);//]
                     outf <<")";                     
                     test(307);//; 
                     outf << ";"<<endl;  
                     outf <<objt<<"."<<"drow_Ligne();" <<endl;              
                  break;   
               case 311:
                  cout << "Rectangle"<< endl;
                   outf << "rectangles "; 
                  test(311);
                  if (tk == 309)
                  {
                     cout << "Rectangle "<<nb<<":" <<endl;
                     outf << obj <<nb;
                     objt=obj+num;
                     test(309);
                  } 
                      A();
                     outf << ")";
                     test(305);//]
                     outf << ";"<<endl;
                     test(307);//; 
                      outf <<objt<<"."<<"drow_Rectangle();" <<endl;  
                  break;
               case 312:
                  cout << "Cercle"<< endl;
                   outf << "cercles "; 
                  ////////////////////////////////////////Cercle/////////////////////////////////////////
                  test(312);
                  if (tk == 309)
                  {
                     cout << "Cercle "<<nb<<":" <<endl;
                     outf << obj <<nb;
                     objt=obj+num;
                     test(309);                 
                  } 
                      C();                   
                     outf << ")";
                     test(305);//]
                     outf << ";"<<endl;
                     test(307);//; 
                   
                      outf <<objt<<"."<<"drow_Cercle();" <<endl;    
                  break;
               case 313:
                  cout << "Carre "<< endl;
                   outf << "carres "; 
                  //////////////////////////////////Carre/////////////////////////////
                  test(313);
                  if (tk == 309)
                  {
                     cout << "Carre "<<nb<<":" <<endl;
                     outf << obj <<nb;
                     objt=obj+num;
                     test(309);                 
                  } 
                      C();                  
                     outf << ")";
                     test(305);//]
                     outf << ";"<<endl;
                     test(307);//;   
                     outf <<objt<<"."<<"drow_Carre();" <<endl;                   
                  break;
               case 314:
                  cout << "Ellipse"<< endl;
                   outf << "ellipses "; ////////////////////////////Ellipse////////////////////////////////////
                  test(314);
                  if (tk == 309)
                  { cout << "Ellipse "<<nb<<":" <<endl;
                     outf << obj <<nb;
                     objt=obj+num;
                     test(309);
                  } 
                      A(); 
                     outf << ")";
                     test(305);//]
                      outf << ";"<<endl;
                     test(307);//; 
                     outf <<objt<<"."<<"drow_Ellipse();" <<endl;
                  break;
               case 315:
                  cout << "Arc "<< endl;
                   outf << "arcs "; ////////////////////////////Arc////////////////////////////////////
                  test(315);
                  if (tk == 309)
                  {  cout << "Arc "<<nb<<":" <<endl;
                     outf << obj <<nb;
                     objt=obj+num;
                     test(309);
                  } 
                      A();
                     test(306);//,
                     outf << ",";
                     cout << nb;
                     test(309);//nb
                     outf << nb ;
                     test(305);//]
                     outf << ")";  
                     test(307);//; 
                     outf << ";"<<endl;
                     outf <<objt<<"."<<"drow_Arc();" <<endl;
                  break; 
               case 316:
                  cout << "Triangle"<< endl;
                   outf << "triangles "; 
                  test(316);
                  if (tk == 309)
                  {  cout << "Triangle "<<nb<<":" <<endl;
                     outf << obj <<nb;
                     objt=obj+num;
                     test(309);
                  } 
                      A(); 
                    
                     test(306);//,
                     outf <<",";
                     if(tk == 302){ //(                        
                       test(302);
                       init();
                     }else{                       
                       test(308);//ID
                        outf << id <<".x";
                        outf << ",";
                        outf << id <<".y";
                     }                      
                     test(305);//]
                     outf << ")";                    
                     test(307);//;                      
                     outf << ";"<<endl;
                     outf<<objt<<"."<<"drow_Triangle();" <<endl;
                  break; }    
            } 
         } 
         Afficher(tk);
         cout<<" FIN PROGRAMME "<<endl;
         outf <<"getch();"<<endl;
         outf <<"closegraph();"<<endl;
         outf <<"return 0;"<<endl;
         outf <<"}"<<endl;
      }else{ cout << "marquer la debut du programme" <<endl; }
}

 int main(){
    fp = fopen("input.txt","r");
    if (fp == NULL)    
    {
        printf("Erreur fopen\n");
    }
    s = getc(fp);
    //outf.seekp(-30,ios::end);
    string line;
    if (inf.is_open())
    {
       while (!inf.eof())
       {
          getline(inf,line);
          outf << line<< endl;
       }
       
    }else{
       cerr << "ERREUR! Impossible d'ecrire dans ce fichier ..." << endl;
       exit(-1);
    }
   inf.close();
   
    parser();
   
   fclose(fp); 
   
  return 0;
}