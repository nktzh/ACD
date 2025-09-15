#include <iostream>
#include <string>


#include <locale>

using namespace std;


enum Zhanr
{
    Adventure,
    Sports,
    Simulator,
    Action,
    Strategy
};

struct Date
{
    int Day;
    int Month;
    int Year;

    Date(int day = 1, int month = 1, int year = 2000)
    {
        Day = day;
        Month = month;
        Year = year;
    }

    string ToString() const
    {
        char buffer[20];
        sprintf_s(buffer, "%02d.%02d.%d", Day, Month, Year);
        return string(buffer);
    }
};

struct Game
{
    string Title;
    Zhanr GameGenre;
    string Publisher;
    Date PurchaseDate;
    bool IsCompleted;

    Game(string title, Zhanr genre, string publisher, Date date, bool completed)
    {
        Title = title;
        GameGenre = genre;
        Publisher = publisher;
        PurchaseDate = date;
        IsCompleted = completed;
    }

    void PrintInformation() const
    {
        cout << "  Тайтл: " << Title << endl;
        cout << "  Разработчик: " << Publisher << endl;
        cout << "  Жанр: " << GameGenreToString(GameGenre) << endl;
        cout << "  Пройдена: " << (IsCompleted ? "ДА" : "НЕТ") << endl;
        cout << "  Дата покупки: " << PurchaseDate.ToString() << endl;
        cout << "+-----------------------------------------+" << endl;
    }

    static string GameGenreToString(Zhanr genre)
    {
        switch (genre)
        {
        case Adventure: return "Adventure";
        case Sports: return "Sports";
        case Simulator: return "Simulator";
        case Action: return "Action";
        case Strategy: return "Strategy";
        default: return "Unknown";
        }
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");

    Game games[] = {
        Game("Cybeprunk 2077", Action, "CD Projekt Red", Date(15, 6, 2020), true),
        Game("FOOTBALL", Sports, "EA Sports", Date(1, 10, 2021), false),
        Game("BIOSHOK", Action, "2K Games", Date(20, 5, 2019), false),
        Game("GTA VI", Action, "RockstAr", Date(10, 3, 2018), true),
        Game("FORZA HORIZON 5", Simulator, "Microsoft", Date(18, 8, 2020), false)
    };

    cout << "  * Игры, которые предстоит пройти:\n" << endl;

    for (const auto& game : games)
    {
        if (!game.IsCompleted)
        {
            game.PrintInformation();
        }
    }

    return 0;
}