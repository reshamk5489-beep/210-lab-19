#include <iostream>
#include <iomanip>
using namespace std;

// Comment #1: Define a struct named Node that contains a double rating, a string comment, and a pointer to the next Node.
struct Node
{
    double rating;
    string comment;
    Node *next;
};

int main()
{
    cout << fixed << setprecision(1);
    srand (time(0));

    int userChoice = 0;
    Node *head = nullptr;
    char yesOrNo;
    double randomRating;

    cout << "Which linked list method should we use?" << endl;
    cout << "[1] New nodes are added at the head of the linked list" << endl;
    cout << "[2] New nodes are added at the tail of the linked list" << endl;
    cout << "Choice: ";

    cin >> userChoice;

    // Comment #2: Write a loop that continues to ask the user to enter review ratings and comments until they choose to stop.
    while (true)
    {
        // Comment #3: Create a new Node.
        Node *temp = new Node;
        temp->next = nullptr;

        randomRating = (rand()) / 5.0;

        // Comment #4: Use cin.ignore() to clear the input buffer before using getline() to read the review comment.
        cin.ignore();

        cout << "Enter review comments: ";
        getline(cin, temp->comment);

        if (head == nullptr)
        {
            // Comment #5: If the linked list is empty, set head to point to the new Node.
            head = temp;
        }
        else 
        {
            // Comment #6: If the linked list is not empty, add the new Node to the head or tail based on userChoice.
            if (userChoice == 1)
            {
                // Comment #7: Add to the front
                temp->next = head;
                head = temp;
            }
            else 
            {
                // Comment #8: Add to the tail
                Node *current = head;
                while (current->next != nullptr)
                {
                    current = current->next;
                }

                current->next = temp;
            }
        }

        cout << "Enter another review? Y/N: ";
        cin >> yesOrNo;
        cin.ignore();

        if (yesOrNo == 'N' || yesOrNo == 'n')
        {
            break;
        }
    }

    cout << "Outputting all reviews:" << endl;

    Node *current = head;
    int reviewNum = 0;
    double total = 0.0;

    // Comment #9: Write a loop that traverses the linked list.
    while (current != nullptr)
    {
        // Comment #10: Calculate the total of the sum of the ratings.
        total += current->rating;
        cout << "\t> Review #" << ++reviewNum << ": " << current->rating << ": " << current->comment << endl;
        
        current = current->next;
    }

    // Comment #11: Calculate the average rating.
    cout << "\t> Average: " << total/reviewNum << endl;

    return 0;
}