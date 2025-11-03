#include <stdio.h>

int main()
{
    int pin =4565;           
    int input_pin;
    float balance;            
    int atm;                  
    float amount;
    int new_pin, confirm_pin;

    printf("Welcome to XYZ ATM\n");

    
    while (1) 
    {
        printf("Enter your PIN: ");
        scanf("%d", &input_pin);
        if (input_pin == pin) 
        {
            printf("PIN verified successfully.\n");
            break;
        } 
        else 
        {
            printf("Invalid PIN. Try again.\n");
        }
    }
   

    while (1) 
    {
        printf("\nATM MENU>>>>>\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Change PIN\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &atm);    
        switch (atm) 
        {         
            case 1:
                printf("Your current balance is: %.2f\n", balance);
                break;

            case 2:
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                if (amount > 0) 
                {
                    balance += amount;
                    printf("Deposit successful. New balance: %.2f\n", balance);
                }
                else 
                {
                    printf("Invalid amount. Try again.\n");
                }
                break;

            case 3:
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                if (amount > 0 && amount <= balance) 
                {
                    balance -= amount;
                    printf("Withdrawal successful. New balance: %.2f\n", balance);
                } 
                else if (amount > balance) 
                {
                    printf("<<<<<<<<<<<<<YOU HAVE LESS BALANCE>>>>>>>>>>>>>\n");
                } 
                else 
                {
                    printf("<<<<<Invalid amount. Try again>>>>>\n");
                }
                break;

            case 4:
                printf("Enter your current PIN: ");
                scanf("%d", &input_pin);
                if (input_pin == pin) 
                {
                    printf("Enter new PIN: ");
                    scanf("%d", &new_pin);
                    printf("Confirm new PIN: ");
                    scanf("%d", &confirm_pin);

                    if (new_pin == confirm_pin) 
                    {
                        pin = new_pin;
                        printf("-------PIN changed successfully-------\n");
                    } 
                    else 
                    {
                        printf("PINs do not match. Try again.\n");
                    }
                } 
                else 
                {
                    printf("Incorrect current PIN.\n");
                }
                break;

            case 5:
                printf("Thank you for using XYZ ATM\n");
                return 0;

            default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
