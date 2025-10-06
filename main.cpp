#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

// Comment #1: Define a struct named Node that contains a double rating, a string comment, and a pointer to the next Node.
struct Node
{
    double rating;
    string comment;
    Node *next;
};

class Movie
{
    private:
        string title;
        Node *head; // Pointer to the head of the linked list
    
    public:
        Movie(string title);
        printOutput();
}

int main()
{
    cout << fixed << setprecision(1);
    srand (time(0));

    Node *head = nullptr;
    double randomRating;
    string reviewComment;

    ifstream inFile("review.txt");
    int i = 0;

    // Comment #2: Write a loop that continues to ask the user to enter review ratings and comments until they choose to stop.
    while (i++ < 5)
    {
        cout << "Processing review #" << i << endl;

        randomRating = (rand() % 41) / 10.0 + 1.0; // Random rating between 1.0 and 5.0
        cout << "\t> Generated random rating: " << randomRating << endl;

        while (getline(inFile, reviewComment))
        {
            if (reviewComment == "") // Movie comments are separated by new lines in the reviews.txt file
            {
                break;
            }

            cout << "\t> Read review comment: " << reviewComment << endl;

            // Comment #3: Create a new Node.
            Node *temp = new Node;
            temp->next = nullptr;

            temp->rating = randomRating;
            temp->comment = reviewComment;

            if (head == nullptr)
            {
                // Comment #5: If the linked list is empty, set head to point to the new Node.
                head = temp;
            }
            else
            {
                temp->next = head;
                head = temp;
            }
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
    cout << "Total: " << total << endl;
    cout << "Total reviews: " << reviewNum << endl;
    cout << "\t> Average: " << total/reviewNum << endl;

    return 0;
}