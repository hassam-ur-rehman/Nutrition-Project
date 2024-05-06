#include <iostream>
#include <vector>
#include <string>
#include <cmath> 
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
    cout << "---------------------------------" << endl;
    cout << "1. LOGIN\t\t\t|" << endl;
    cout << "---------------------------------" << endl;
    cout << "2. REGISTER\t\t\t|" << endl;
    cout << "---------------------------------" << endl;
    cout << "3. GET INFO\t\t\t|" << endl;
    cout << "---------------------------------" << endl;

    cin >> n;
    cout << "______________________________________________________________________________________________________" << endl;
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
    cout << "\t\t\t\t\t--------------------------------\t\t\t\t" << endl << endl;
    cout << "\t\t\tYou need to login back for the smooth operation of app" << endl;
    cout << "\t\t\t_______________________________________________________" << endl;
}
void generalinfo()
{
    char  n;
    cout << "____________________________________________________________________________" << endl;
    cout << "| What you want know about diet ? Choose the respective character from menu " << endl;
    cout << "____________________________________________________________________________" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "| a. Healthy BMI                            |" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "| b. Maintain BMI                           |" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "| c. For  Blood Pressure Patient            |" << endl;
    cout << "---------------------------------------------" << endl;
    cin >> n;
    switch (n)
    {
    case 'a':
        cout << "----------------------------------------------------------------------------------------"<<endl;
        cout << "| The range considered healthy varies slightly depending on the source, but generally: |"<<endl; 
        cout << "| 1.BMI below 18.5 is considered underweight                                           |"<<endl;
        cout << "| 2.BMI between 18.5 and 24.9 is considered normal or healthy weight                   |"<<endl;
        cout << "| 3.BMI between 25 and 29.9 is considered overweigh                                    |"<<endl;
        cout << "| 4.BMI of 30 or higher is considered obese                                            |"<<endl;
        cout << "----------------------------------------------------------------------------------------" << endl;
        break;
    case 'b':
        // Code for Maintain BMI
        break;
    case 'c':
        // Code for Healthy Diet for Blood Pressure Patient
        break;
    default:
        cout << "INVALID COMMAND !!";
    }
}

void generateDietPlan(bool hasDiabetes, bool hasHighBloodPressure, bool hasGlutenIntolerance) {
    cout << "Here is your personalized diet plan:" << endl;

    // Non-vegetarian foods
    vector<string> nonVegFoods = { "Chicken breast", "Salmon", "Turkey", "Lean beef", "Eggs" };

    // Vegetarian foods
    vector<string> vegFoods = { "Spinach", "Broccoli", "Quinoa", "Lentils", "Tofu" };

    // Drinks
    vector<string> drinks = { "Water", "Green tea" };

    // Remove foods based on user's conditions
    if (hasDiabetes) {
        // Remove foods not suitable for diabetes
        nonVegFoods.erase(remove(nonVegFoods.begin(), nonVegFoods.end(), "Salmon"), nonVegFoods.end());
        vegFoods.erase(remove(vegFoods.begin(), vegFoods.end(), "Quinoa"), vegFoods.end());
        drinks.erase(remove(drinks.begin(), drinks.end(), "Green tea"), drinks.end());
    }

    if (hasHighBloodPressure) {
        // Remove foods not suitable for high blood pressure
        nonVegFoods.erase(remove(nonVegFoods.begin(), nonVegFoods.end(), "Salmon"), nonVegFoods.end());
        vegFoods.erase(remove(vegFoods.begin(), vegFoods.end(), "Spinach"), vegFoods.end());
        drinks.erase(remove(drinks.begin(), drinks.end(), "Green tea"), drinks.end());
    }
    if (hasGlutenIntolerance) {
        // Remove foods not suitable for high blood pressure
        nonVegFoods.erase(remove(nonVegFoods.begin(), nonVegFoods.end(), "Turkey"), nonVegFoods.end());
        vegFoods.erase(remove(vegFoods.begin(), vegFoods.end(), "Tofu"), vegFoods.end());
        drinks.erase(remove(drinks.begin(), drinks.end(), "Water"), drinks.end());
    }

    // Display recommendations
    cout << "Non-Vegetarian Foods:" << endl;
    for (const auto& food : nonVegFoods) {
        cout << "- " << food << endl;
    }

    cout << "Vegetarian Foods:" << endl;
    for (const auto& food : vegFoods) {
        cout << "- " << food << endl;
    }

    cout << "Drinks:" << endl;
    for (const auto& drink : drinks) {
        cout << "- " << drink << endl;
    }
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
                cout << "__________________________________________________________________________________________________________" << endl << endl;
                cout << "\t\t\t\t\t---------------------\t\t\t\t" << endl;
                cout << "\t\t\t\t\t| Login successful! |\t\t\t\t" << endl;
                cout << "\t\t\t\t\t---------------------\t\t\t\t" << endl;
                DietTracker tracker;
                // Display UI
                cout << "\t\t\t ------------------------------------------"<<endl;
                cout << "\t\t\t|      FOR YOUR PERSONALISED DIET PLAN    |" << endl;
                cout << "\t\t\t------------------------------------------"<<endl;
                cout << "----------------------------------------------------"<<endl;
                cout << "Please answer the following questions:" << endl;

                // Prompt user for medical conditions
                cout << "Do you have diabetes? (yes/no): ";
                string hasDiabetes;
                cin >> hasDiabetes;

                cout << "Do you have high blood pressure? (yes/no): ";
                string hasHighBloodPressure;
                cin >> hasHighBloodPressure;

                cout << "Do you have gluten intolerance? (yes/no): ";
                string hasGlutenIntolerance;
                cin >> hasGlutenIntolerance;

                // Process user input and generate diet plan
                bool diabetes = (hasDiabetes == "yes");
                bool highBloodPressure = (hasHighBloodPressure == "yes");
                bool glutenIntolerance = (hasGlutenIntolerance == "yes");

                generateDietPlan(diabetes, highBloodPressure, glutenIntolerance);

                cout << "Thank you for using the Nutrition Application!" << endl;
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
        case 3:
            generalinfo();
            break;
        default:
            cout << "Invalid choice." << endl;
            break;
        }
    } while (n != 3);

    return 0;
}
