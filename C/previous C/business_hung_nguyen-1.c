#include <stdio.h>
#include <stdlib.h>
// Name: Hung Nguyen
// ID: 1001721494
// 1320-Section 004
float print_out(float*salary,int* num_of_emp)
{

    int managers;
    int directors;
    float d_salary=0.0;
    float m_salary=0.0;
    float now_budget=0.0;

        if(*num_of_emp<6)
        {
            printf("Error");
        }
        managers=*num_of_emp/2;
        directors=managers/3;
        if (managers < 3)
        {
            directors=0;
        }

        d_salary = *salary * 5 ;
        m_salary=d_salary/2;

        printf("\n\n\n**Employee info:**\n");
        printf("Total workers: %d  Monthly salary: $%.2f\n",*num_of_emp,*salary);
        printf("Total managers: %d Monthly salary: $%.2f\n",managers,m_salary);
        printf("Total directors: %d Monthly salary: $%.2f\n",directors,d_salary);


        //printf("d salary: %f",d_salary);
        //printf("m salary: %f",m_salary);





    now_budget=*salary * (*num_of_emp)+ m_salary*managers + d_salary* directors;

        printf("Total spent: %.2f\n ",now_budget);

        return now_budget;
}

int rebudget(float*d,float *budget)
{
    int ans;
    float final_budget;

    final_budget = *budget-*d;

    printf("--This goes UNDER your budget by $%.2f\n\n\n",final_budget);
    printf("Would you like to rebudget? 1 for yes 2 for no\n");
    scanf("%d",&ans);

    if (ans == 1)
    {
        return 1;
    }
    else
    {
        printf("Bye!");
        return 0;
    }


   // scanf("%d",ans);

   // return ans;



}

int main()
{
   int i=1;
   float budget, total, salary;
   float* money_ptr=&salary;
   float*total_ptr=&total;
   int employees;

    printf("Enter monthly budget: $");
    scanf("%f",&budget);

   while(i)
   {

        printf("Enter monthly worker salary: $");
        scanf ("%f", &salary);

        printf("Enter total worker:");
        scanf ("%d",&employees);

        total=print_out(money_ptr,&employees);
        i=rebudget(total_ptr,&budget);


   }
}
