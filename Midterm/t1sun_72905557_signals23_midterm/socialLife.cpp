//Provided code
/**
 * This function calculates a grade.
 * Returns 'A' if you are an Engineer AND you do NOT have a rich uncle AND you have 1 inputTry
 * Returns 'B' if you are an (Engineer OR Poet) AND you do NOT have a rich uncle, AND you less than 3 inputTry(s)
 * Returns 'C' if you have a rich uncle
 * Else Returns 'D' 
 
 * @param avatar - avatar value (1 = Engineer, 2=Poet) //Can assume only one of these numbers
 * @param richUncle - true for a rich uncle, false otherwise
 * @param inputTry - An integer that says how many times it took to enter a valid avatar
 */
extern const int ENGINEER;
extern const int POET;

//Put calcGrade function here as described in socialLife.h
char calcGrade(int avatar, bool richUncle, int inputTry) {
    if (avatar == 1 && richUncle == false && inputTry == 1) {
        return 'A';
    }
    else if ((avatar == 1 || avatar == 2) && richUncle == false && inputTry < 3) {
        return 'B';
    }
    else if (richUncle == true){
        return 'C';
    }
    else {
        return 'D';
    }
}




