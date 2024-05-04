#include <iostream>
#include <vector>
#include <string>
#include <cmath> // for pow function
using namespace std;

class User
{
private:
    string username;
    string password;
    int age;
    float height;
    float weight;

public:
    User(string _username, string _password, int _age, float _height, float _weight) : username(_username), password(_password), age(_age), height(_height), weight(_weight) {}

    string getUsername() const
    {
        return username;
    }

    bool checkPassword(string _password) const
    {
        return password == _password;
    }

    double calculateBMI() const
    {
        // BMI formula: weight (kg) / (height (m) * height (m))
        return weight / pow(height / 100, 2); // Convert height from cm to meters
    }

    void displayUserInfo() const
    {
        cout << "Username: " << username << endl;
        cout << "Age: " << age << endl;
        cout << "Height: " << height << " cm" << endl;
        cout << "Weight: " << weight << " kg" << endl;
        cout << "BMI: " << calculateBMI() << endl;
    }
};

class Food
{
private:
    string name;
    int calories;

public:
    Food(string _name, int _calories) : name(_name), calories(_calories) {}

    string getName() const
    {
        return name;
    }

    int getCalories() const
    {
        return calories;
    }
};

class DietTracker
{
private:
    vector<Food> foods;
    int totalCalories;

public:
    DietTracker() : totalCalories(0) {}

    void addFood(const Food& food)
    {
        foods.push_back(food);
        totalCalories += food.getCalories();
    }

    void display() const
    {
        cout << "Diet Tracker:" << endl;
        for (const auto& food : foods)
        {
            cout << "Food: " << food.getName() << ", Calories: " << food.getCalories() << endl;
        }
        cout << "Total Calories: " << totalCalories << endl;
    }
};

bool login(const vector<User>& users, string username, string password)
{
    for (const auto& user : users)
    {
        if (user.getUsername() == username && user.checkPassword(password))
        {
            return true;
        }
    }
    return false;
}

int startup()
{
    int n;
    cout << "---------------------------------------------------------------------------------------------------------" << endl;
    cout << "|\t\t\t\t\tNUTRITION AND DIET PLANNER\t\t\t\t\t|" << endl;
    cout << "---------------------------------------------------------------------------------------------------------" << endl;
    cout << "CHOOSE WHAT YOU WANT TO DO\t| " << endl;
    cout << "---------------------------------"<<endl;
    cout << "1. LOGIN\t\t\t|" << endl;
    cout << "---------------------------------"<<endl;
    cout << "2. REGISTER\t\t\t|" << endl;
    cout << "---------------------------------"<<endl;
    cout << "3. GET INFO\t\t\t|" << endl;
    cout << "---------------------------------"<<endl;

    cin >> n;
    cout << "______________________________________________________________________________________________________"<<endl;
    return n;
}

void registerUser(vector<User>& users)
{
    string username, password;
    int age;
    float height, weight;

    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;
    cout << "Enter Age: ";
    cin >> age;
    cout << "Enter Height (in cm): ";
    cin >> height;
    cout << "Enter Weight (in kg): ";
    cin >> weight;

    users.push_back(User(username, password, age, height, weight));
    cout << "\t\t\t\t\t--------------------------------\t\t\t\t" << endl;
    cout << "\t\t\t\t\t| User Registered Successfully! |" << endl;
    cout << "\t\t\t\t\t--------------------------------\t\t\t\t" << endl;
    cout << "You need to login back for the smooth operation of app";
}

int main()
{
    int n;
    vector<User> users = {
        User("talha", "123", 20, 175, 72), // Sample user with age 25, height 175 cm, and weight 70 kg
        User("hassam", "456", 21, 173, 68) // Sample user with age 30, height 180 cm, and weight 80 kg
    };

    do
    {
        n = startup();

        switch (n)
        {
        case 1:
        {
            string username, password;

            cout << "Username: ";
            cin >> username;
            cout << "Password: ";
            cin >> password;

            if (login(users, username, password))
            {
                cout << "__________________________________________________________________________________________________________" <<endl<< endl;
                cout << "\t\t\t\t\t---------------------\t\t\t\t"<<endl;
                cout << "\t\t\t\t\t| Login successful! |\t\t\t\t" << endl;
                cout << "\t\t\t\t\t---------------------\t\t\t\t"<<endl;
                 DietTracker tracker;

                Food apple("Apple", 52);
                Food banana("Banana", 105);
                Food salad("Salad", 150);

                tracker.addFood(apple);
                tracker.addFood(banana);
                tracker.addFood(salad);

                tracker.display();

                cout << "User Info:" << endl;
                for (const auto& user : users)
                {
                    if (user.getUsername() == username)
                    {
                        user.displayUserInfo();
                        break;
                    }
                }
            }
            else
            {
                cout << "Invalid username or password. Please try again." << endl;
                cout << "__________________________________________________________________________________________________________" << endl;
            }
            break;
        }
        case 2:
            registerUser(users);
            break;
        default:
            cout << "Invalid choice." << endl;
            break;
        }
    } while (n != 3);

    return 0;
}

