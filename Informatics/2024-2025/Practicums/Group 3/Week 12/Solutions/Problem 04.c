#include <stdio.h>



void clearStandardInput();



unsigned int readStairs();



unsigned int countWays(unsigned int stairs);



int main() {
    unsigned int stairs = readStairs(       )   ;
    unsigned int ways   = countWays (stairs )   ;

    printf("The number of ways are: %u\n", ways);

    return 0;
}



void clearStandardInput() {
    int c = 0;

    while ((c = getchar()) && c != '\n' && c != EOF);
}



unsigned int readStairs() {
    unsigned int stairs =   0;
    int inputArgument   =   0;

    do {
        printf("Enter the number of stairs: ");

        inputArgument = scanf("%u", &stairs);

        if (inputArgument != 1) {
            clearStandardInput();
        }
    } while (inputArgument != 1 || stairs == 0);

    return stairs;
}



unsigned int countWays(unsigned int stairs) {
    /*
        If John is on Stair 1, there is     1 way   - climbing 1 stair  in 1 move.
        If John is on Stair 2, there are    2 ways  - climbing 2 stairs in 2 moves or in 1 move.
        If John is on Stair N, the number of ways are equal to the sum of next two results:
            The number of ways, which he has been before 1 stair    and now he makes another move with 1 stair  .
            The number of ways, which he has been before 2 stairs   and now he makes another move with 2 stairs .
        Warning:    What happens, when he is on Stair N - 2 and he makes 2 moves to get to Stair N? 
                    We have already calculated this in the case for Stair N - 1.
                    This way we count only the unique ways to get to Stair N.
    
                1,                      S = 1
        W(N) =  2,                      S = 2
                W(N - 1) + W(N - 2),    S > 2
    */

    if (stairs == 1) {
        return 1;
    }

    if (stairs == 2) {
        return 2;
    }

    return countWays(stairs - 1) + countWays(stairs - 2);
}
