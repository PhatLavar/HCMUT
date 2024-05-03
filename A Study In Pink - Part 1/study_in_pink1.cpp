#include "study_in_pink1.h"

bool readFile(
        const string & filename,
        int & HP1,
        int & HP2,
        int & EXP1,
        int & EXP2,
        int & M1,
        int & M2,
        int & E1,
        int & E2,
        int & E3
) {
    // This function is used to read the input file,
    // DO NOT MODIFY THIS FUNCTION
    ifstream ifs(filename);
    if (ifs.is_open()) {
        ifs >> HP1 >> HP2
            >> EXP1 >> EXP2
            >> M1 >> M2
            >> E1 >> E2 >> E3;
        return true;
    }
    else {
        cerr << "The file is not found" << endl;
        return false;
    }
}

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////
//Check to let the variable in their limit
int check (int N, int initial, int final) {
    if (N < initial) {return initial;}
    if (N > final)   {return final;}
    else             {return N;}
}

int addM (int &M, double add) {
    float temp = M;
    temp = temp + add;
    M = ceil(temp);
    M =check(M, 0, 3000);
    return M;
}

int addExp (int &Exp, double add) {
    float temp = Exp;
    temp = temp + add;
    Exp = ceil(temp);
    Exp =check(Exp, 0, 600);
    return Exp;
}

int addHp (int &Hp, double add) {
    float temp = Hp;
    temp = temp + add;
    Hp = ceil(temp);
    Hp =check(Hp, 0, 666);
    return Hp;
}

/*
check(M, 0, 3000);
check(EXP, 0, 600);
check(HP, 0, 666);
*/


// Task 1
int Decision(int & e1, int & exp1) {
    int D = 3*e1 + 7*exp1;
    if (D%2 == 0) {addExp(exp1, D/200);}
    else          {addExp(exp1, -D/100);}
    return exp1;
}

int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (e1 < 0 || e1 > 99) {
        return -99;
    } else                 {
        double e1_1 = e1/4.0 + 19;   
        double e1_2 = e1/9.0 + 21;  
        double e1_3 = e1/16.0 + 17;  
        
             if (e1 == 0) {exp2 = addExp(exp2, 29); exp1 = Decision(e1, exp1);}
        else if (e1 == 1) {exp2 = addExp(exp2, 45); exp1 = Decision(e1, exp1);}
        else if (e1 == 2) {exp2 = addExp(exp2, 75); exp1 = Decision(e1, exp1);}
        else if (e1 == 3) {exp2 = addExp(exp2, 149); exp1 = Decision(e1, exp1);}
        else if (e1 >=  4 && e1 <= 19) {exp2 = addExp(exp2, e1_1); exp1 = addExp(exp1, -e1);}
        else if (e1 >= 20 && e1 <= 49) {exp2 = addExp(exp2, e1_2); exp1 = addExp(exp1, -e1);}
        else if (e1 >= 50 && e1 <= 65) {exp2 = addExp(exp2, e1_3); exp1 = addExp(exp1, -e1);}
        else if (e1 >= 66 && e1 <= 79) {
                                       exp2 = addExp(exp2, e1_1);
                                       if (exp2 > 200) {
                                                        exp2 = addExp(exp2, e1_2); 
                                                       }
                                       exp1 = addExp(exp1, -e1);
                                       }
        else                           {
                                       exp2 = addExp(exp2, e1_1);
                                       exp2 = addExp(exp2, e1_2);
                                       if (exp2 > 400) {
                                                       exp2 = addExp(exp2, e1_3);
                                                       exp2 = addExp(exp2, 0.15*exp2);
                                                       }
                                       exp1 = addExp(exp1, -e1);
                                       }     
    }
return exp1 + exp2;
}

// Task 2
int nearSquare(int & EXP1) {
    EXP1 = check(EXP1, 0, 600);
    int S1, S2;
    for (int i = 1; i <= ceil(sqrt(EXP1)); i++) {
        if (i * i >= EXP1) {
            S1 = i * i;
            S2 = (i - 1) * (i - 1);
            break;
        }
    }
    int N1 = abs(S1 - EXP1);
    int N2 = abs(S2 - EXP1);
    if (N1 > N2) {
        return S2;
    } else {
        return S1;
    }
}

int suitcaseProbability(int N, int & EXP1) {
    int P;
    if (N <= EXP1) {P = 1.00;}
    else           {P = 1.00*(EXP1/N + 80)/123;}
    return P;
}

int buyingFood (int & M1, int & HP1) {
    HP1 = check(HP1, 0, 666);
    M1 = check(M1, 0, 3000);
    if (M1 > 0) {
        if (HP1 < 200) {HP1 = addHp(HP1, 0.30*HP1);
                        M1 = M1 - 150;
                       }
        else           {HP1 = addHp(HP1, 0.10*HP1);
                        M1 = M1 - 70;
                       }
    }
    else        {return HP1;}
    return HP1;
}

int rentTransport (int & M1, int & EXP1) {
    EXP1 = check(EXP1, 0, 600);
    M1 = check(M1, 0, 3000);
    if (M1 > 0) {
        if (EXP1 < 400) {EXP1 = addExp(EXP1, 0.13*EXP1);
                         M1 = M1 - 200; 
                        }
        else            {EXP1 = addExp(EXP1, 0.13*EXP1);
                         M1 = M1 - 120;}
    }
    else         {return EXP1;}
    return EXP1;
}

int homelessPerson (int & M1, int & EXP1) {
    EXP1 = check(EXP1, 0, 600);
    M1 = check(M1, 0, 3000);
    if (M1 > 0) {
        if (EXP1 < 300) {M1 = M1 - 100;}
        else            {M1 = M1 - 120; 
                         EXP1 = addExp(EXP1, -0.10*EXP1);}
    }
    else        {return EXP1;}
    return EXP1;    
}

int suitcaseRoad3 (int E2) {
    int P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int Prob;
    int sum = (E2 / 10) + (E2 % 10);
    int digit = sum % 10;
    
    for (int i = 0; i < 10; i++) {
        if (i == digit) {Prob = P[i]*0.01;}
        break;
    }
    return Prob;
}

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    double Half = M1 / 2;
    if (E2 < 0 || E2 > 99) {
        return -99;
    } else                 {
    // Road 1:
    int N1 = nearSquare(EXP1);
    double P1 = suitcaseProbability(N1, EXP1);

    // Road 2:
    if (E2 % 2 == 0) {
        while (M1 > 0) {
            int EXP1 = rentTransport(M1, EXP1); 
                         if (M1 < 0) {M1 = 0; break;}
                         else        {EXP1 = homelessPerson(M1, EXP1);
                                      if (M1 < 0) {M1 = 0;}
                                     }
                        
            break;
        }
        addHp(HP1, -0.17*HP1);
        addExp(EXP1, 0.17*EXP1);

    } else {
        while (M1 >= Half) {
            HP1 = buyingFood(M1, HP1);
            if (M1 < Half) {break;}
            else           {EXP1 = rentTransport(M1, EXP1); 
                            if (M1 < Half) {break;}
                            else           {EXP1 = homelessPerson(M1, EXP1);
                                                if (M1 < Half) {break;}
                                            }
                            }  
            }
        M1 = check(M1, 0, 3000);
        addHp(HP1, -0.17*HP1);
        addExp(EXP1, 0.17*EXP1);
    }
        
        int N2 = nearSquare(EXP1);
        double P2 = suitcaseProbability(N2, EXP1);

        // Road 3:
        double P3 = suitcaseRoad3(E2);

        if (P1 == 1.00 && P2 == 1.00 && P3 == 1.00) {addExp(EXP1, -0.25*EXP1); 
                                                    }
        else { double P_avg = (P1 + P2 + P3) / 3.00;
               if (P_avg < 0.50) {addHp(HP1, -0.15*HP1);
                                  addExp(EXP1, 1.15*EXP1);
                                 }
               else              {addHp(HP1, -0.10*HP1);
                                  addExp(EXP1, 0.20*EXP1);
                                 }  
        }    
    }
    
    return HP1 + EXP1 + M1; 
}


// Task 3
int findNum (int Num) {
    while (Num >= 10 && Num <= 99) {
        Num = (Num / 10) + (Num % 10);
    }
    return Num;
}

int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3) {
    if (E3 < 0 || E3 > 99) {
        return -99;
    } else {
        
        HP1 = check(HP1, 0, 666);
        HP2 = check(HP2, 0, 666);
        EXP1 = check(EXP1, 0, 600);
        EXP2 = check(EXP2, 0, 600);

        int a[10][10];
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                a[i][j] = (E3 * j + 2 * i) * (i - j);
            }
        }

        int count_i = 0;
        int count_j = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (a[i][j] > 2 * E3) {
                    count_i++;
                }
                if (a[i][j] < -E3) {
                    count_j++;
                }
            }
        }

        // Find numbers b and c using findNum function
        int b = findNum(count_i);
        int c = findNum(count_j);

        // Initialize taxi and max
        int taxi = a[b][c];
        int max = taxi;

        // Update max based on various directions
        for (int i = 0; i < 10; i++) {
            if (a[b][c] > max) {
                max = a[b][c];
            }
            if (b == 9 || c == 9) {break;}
            b++; c++;
        }

        //Reset b and c
        b = findNum(count_i);
        c = findNum(count_j);
        for (int i = 0; i < 10; i++) {
            if (a[b][c] > max) {
                max = a[b][c];
            }
            if (b == 0|| c == 0) {break;}
            b--; c--;
        }

        b = findNum(count_i);
        c = findNum(count_j);
        for (int i = 0; i < 10; i++) {
            if (a[b][c] > max) {
                max = a[b][c];
            }
            if (b == 9|| c == 0) {break;}
            b++; c--;
        }

        b = findNum(count_i);
        c = findNum(count_j);
        for (int i = 0; i < 10; i++) {
            if (a[b][c] > max) {
                max = a[b][c];
            }
            if (b == 0|| c == 9) {break;}
            b--; c++;
        }

        if (abs(max) < abs(taxi)) {
            addExp(EXP1, -0.12*EXP1); addExp(EXP2, -0.12*EXP2);
            addHp(HP1, -0.10*HP1); addHp(HP2, -0.10*HP2);
            return taxi;
        } else {
            addExp(EXP1, 0.12*EXP1); addExp(EXP2, 0.12*EXP2);
            addHp(HP1, 0.10*HP1); addHp(HP2, 0.10*HP2);
            return max;
        }
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    int sLength = 0;
    while (s[sLength] != '\0') {
        sLength++;
    }
    string sNew(s); //Convert char* to string: sNew = s.
    
    
    int eLength = 0;
    while (email[eLength] != '\0') {
        eLength++;
    }
    string eNew(email); //Convert char* to string: eNew = email.
    

    //Finding se
    int atPosition = eNew.find('@');
    string se = eNew.substr(0, atPosition);

    //too-short length (<8)?
    if (sLength < 8) {return -1;}

    //too-long length (>20)? 
    if (sLength > 20) {return -2;} 

    //having string se?
    if (sNew.find(se) != string::npos) {return -(300 + sNew.find(se));}

    //having over-double symbol?
    for (int i = 0; i < sLength - 3; i++) {
        if (sNew[i] == sNew[i+1] && sNew[i+1] == sNew[i+2]) {return -(400 + i);}
    }

    //dont have any special symbols? [return -5;]
    if (sNew.find_first_of("@#%$!") == string::npos) {return -5;}

    //other situation? (have other special symbols...) [return firstPosition of it;]
    for (int i = 0; i < sLength; i++) {  
        if (!((sNew[i] >= '0' && sNew[i] <= '9') ||
             (sNew[i] >= 'a' && sNew[i] <= 'z')  ||
             (sNew[i] >= 'A' && sNew[i] <= 'Z')  ||
             (sNew[i] == '@' || sNew[i] == '#'   || sNew[i] == '%' || sNew[i] == '$' || sNew[i] == '!'))) {
            return i; 
        }
    } 
    return -10;  
}

//Task 5:
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // Make a matrix to record the frequency and the length. 
    int passwordInfo[num_pwds][2] = {0};

    // Update 
    for (int i = 0; i < num_pwds; ++i) {
        int length = strlen(arr_pwds[i]); // Use strlen to get string length
        int count = 1;
        for (int j = i + 1; j < num_pwds; ++j) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) { // Use strcmp for string comparison
                ++count;
            }
        }
        passwordInfo[i][0] = count;  // The first row to record the frequency.
        passwordInfo[i][1] = length; // The second row to record the length.
    }

    int maxFrequency = 0;
    int maxLength = 0;
    int first_pwds = 0; // Initialize first_pwds to avoid uninitialized variable warning
    for (int i = 0; i < num_pwds; ++i) {
        if (passwordInfo[i][0] > maxFrequency || (passwordInfo[i][0] == maxFrequency && passwordInfo[i][1] > maxLength)) {
            maxFrequency = passwordInfo[i][0];
            maxLength = passwordInfo[i][1];
            first_pwds = i;
        }
    }

    return first_pwds;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
