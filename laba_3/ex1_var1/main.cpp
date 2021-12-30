#include <iostream>
using namespace std;
#include "ILoggable.h"
#include "ExpressionEvaluator.h"
#include "CustomExpressionEvaluator.h"
#include "IShuffle.h"
#include "Multiplier.h"
#include "Subtractor.h"

int main() {
	
    double opsCustom[] = { 5, 16, -3, 10, 12 ,2 }; 
    double opsSub[] = { 5.6, -2.1, 3.2, 1.5 }; 

    string filename = "log.txt";
    ExpressionEvaluator* examplesObjects[3]; 

    examplesObjects[0] = new CustomExpressionEvaluator(); 
    examplesObjects[0]->setOperands(opsCustom, 6); 

    examplesObjects[1] = new Substractor(); 
    examplesObjects[1]->setOperands(opsSub, 4);

    examplesObjects[2] = new Multiplier(); 
    examplesObjects[2]->setOperand(0, 1.5);
    examplesObjects[2]->setOperand(1, -8); 
    examplesObjects[2]->setOperand(2, 2.5); 

    for (size_t i = 0; i < 3; i++) {
        examplesObjects[i]->logToFile(filename); 
        examplesObjects[i]->logToScreen(); 
    }

    cout << "\n\ndo shuffle\n" << endl;
    for (size_t i = 0; i < 3; i++) {
       
        CustomExpressionEvaluator* customExpression = dynamic_cast<CustomExpressionEvaluator*>(examplesObjects[i]); 
        if (customExpression) {
            customExpression->shuffle(); 
            customExpression->logToScreen(); 
        }
       
        Substractor* substractor = dynamic_cast<Substractor*>(examplesObjects[i]);
        if (substractor) {
            substractor->shuffle(); 
            substractor->logToScreen(); 
        }
    }

	system("pause");
	return 0;
}