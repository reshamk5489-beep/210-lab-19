#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

const int MOVIE_COUNT = 4;

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
    cout << fixed << setprecision(1);
    srand (time(0));

    double randomRating;
    string reviewComment;

    vector<Movie> movies(MOVIE_COUNT);
    movies[0].setTitle("Titanic");
    movies[1].setTitle("Twilight");
    movies[2].setTitle("Avatar");
    movies[3].setTitle("Jurassic Park");

    ifstream inFile("review.txt");
    int i = 0;

    // Comment #2: Write a loop that continues to ask the user to enter review ratings and comments until they choose to stop.
    while (i < MOVIE_COUNT)
    {
        while (getline(inFile, reviewComment))
        {
            if (reviewComment == "") // Movie comments are separated by new lines in the reviews.txt file
            {
                break;
            }

            // Comment #3: Create a new Node.
            Node *temp = new Node;
            temp->next = nullptr;

            randomRating = (rand() % 41) / 10.0 + 1.0; // Random rating between 1.0 and 5.0

            temp->rating = randomRating;
            temp->comment = reviewComment;

            movies[i].addNodeToHead(temp);
        }

        i++;
    }

    cout << "Outputting all reviews:" << endl << endl;
    
    for (int i = 0; i < MOVIE_COUNT; ++i)
    {
        movies[i].printOutput();
    }

    return 0;
}