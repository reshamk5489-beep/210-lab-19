#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// Comment #1: Define a constant integer named MOVIE_COUNT and set it to 4.
const int MOVIE_COUNT = 4;

// Comment #2: Define a struct named Node that contains a double rating, a string comment, and a pointer to the next Node.
struct Node
{
    double rating;
    string comment;
    Node *next;
};

// Comment #3: Define a class named Movie that contains a string title and a pointer to the head of a linked list of Nodes.
class Movie
{
    private:
        string title;
        Node *head; // Comment #4: Pointer to the head of the linked list.
    
    public:
        Movie()
        {
            title = "";
            head = nullptr;
        }

        string getTitle() const
        {
            return title;
        }

        void setTitle(string movieTitle)
        {
            title = movieTitle;
        }

        void addNodeToHead(Node *node)
        {
            if (head == nullptr)
            {
                // Comment #5: If the linked list is empty, set head to point to the new Node.
                head = node;
            }
            else
            {
                // Comment #6: If the linked list is not empty, set the new Node's next pointer to point to the current head, and then update head to point to the new Node.
                node->next = head;
                head = node;
            }        
        }

        void printOutput() const
        {
            Node *current = head;
            int reviewNum = 0;
            int commentCount = 0;
            double total = 0.0;

            cout << "Movie Title: " << title << endl;

            while (current != nullptr)
            {
                commentCount++;        
                total += current->rating;
                // Comment #10: Calculate the total of the sum of the ratings.
                cout << "\t> Review #" << ++reviewNum << ": " << current->rating << ": " << current->comment << endl;

                current = current->next;
            }

            cout << "\t> Average: " << total/commentCount << endl;
        }
};

int main()
{
    // Comment #7: Set the output to display one decimal place.
    cout << fixed << setprecision(1);

    // Comment #8: Seed the random number generator using the current time.
    srand (time(0));

    double randomRating;
    string reviewComment;

    // Comment #9: Create a vector of Movie objects with a size of MOVIE_COUNT.
    vector<Movie> movies(MOVIE_COUNT);
    movies[0].setTitle("Titanic");
    movies[1].setTitle("Twilight");
    movies[2].setTitle("Avatar");
    movies[3].setTitle("Jurassic Park");

    // Comment #10: Open the file reviews.txt for reading
    ifstream inFile("review.txt");
    int i = 0;

    // Comment #11: Use a while loop to read reviews from the file and add them to the linked list of the corresponding Movie object.
    while (i < MOVIE_COUNT)
    {
        while (getline(inFile, reviewComment))
        {
            if (reviewComment == "") // Comment #12: If an empty line is encountered, break out of the inner loop to move to the next movie.
            {
                break;
            }

            // Comment #13: Create a new Node.
            Node *temp = new Node;
            temp->next = nullptr;

            randomRating = (rand() % 41) / 10.0 + 1.0; // Comment #14: Random rating between 1.0 and 5.0

            temp->rating = randomRating;
            temp->comment = reviewComment;

            // Comment #15: Add the new Node to the head of the linked list for the current Movie object.
            movies[i].addNodeToHead(temp);
        }

        i++;
    }

    // Comment #16: Close the file after reading all reviews.
    inFile.close();

    cout << "Outputting all reviews:" << endl << endl;
    
    // Comment #17: Print each Movie's title, reviews, and average rating.
    for (int i = 0; i < MOVIE_COUNT; ++i)
    {
        movies[i].printOutput();
    }

    return 0;
}