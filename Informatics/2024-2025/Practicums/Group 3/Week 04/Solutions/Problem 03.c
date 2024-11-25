// Author:      Teodor Dishanski
// Institution: Sofia University, Faculty of Mathematics and Informatics

int main() {
    unsigned int number = 0;

    printf("Enter the number: ");
    scanf(&number);

    printf("Is the number even? ", (number & 1) ? "Yes\n" : "No\n");

    return 0;
}