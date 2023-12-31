/**
 * Author: Hifza Nazir 
 * Date: 2023/10/22
 * Email: hifzanazir456@gmail.com
 * 
 * The prgram about 401(k) plan is a account for people to save money for retirement
*/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
    //make variable according to program 
    float initialAmount, monthlyContributionAmount, annualReturn, annualInflation, balance;
    float interest, adjustInflationReturnRate, totalInterestEarned=0;

    //year and month take in integer because they have no decimale point
    int retirementYear, month;

    //prompt the input from user
    printf("Enter the initial Amount:");
    scanf("%f",&initialAmount);
    printf("How much money you can add on monthly base(monthly amount same over life of saving):");
    scanf("%f",&monthlyContributionAmount);
    printf("Average annual rate of return(on scale 0,1):");
    scanf("%f",&annualReturn);
    printf("Average rate of inflation(on scale 0,1):");
    scanf("%f",&annualInflation);
    printf("Enter a number of year untile retirement:");
    scanf("%i",&retirementYear);

    //change the year into month
    month=retirementYear*12;

    //find adjust inflation and return rate
    adjustInflationReturnRate = ((1 + annualReturn )/(1 + annualInflation)) - 1;
    printf("|month|\t|Interset   |\t|Balance             |\n");

    //Using loop and repeate the loop according the number of month
    //Find interest, number of months, amount/month and calculate total total interest and total Amount 
    for(int i = 1; i<=month; i++){
        interest=(adjustInflationReturnRate*initialAmount)/12;
        initialAmount+= interest + monthlyContributionAmount;
        totalInterestEarned = totalInterestEarned + interest;
        printf("|%5i|\t|$ %10.2f|\t|& %10.2f   |\n",i,interest,initialAmount); 
    }

    // print the result...
    printf("__________________________________________________\n");
    printf("Total interest Earned = $ %f\n",totalInterestEarned);
    printf("Total Nest Egg : $ %f\n",initialAmount);
    return 0; 
}