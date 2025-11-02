#include <iostream>
#include <string>
using namespace std;

struct Day
{
    int dayNumber;
    string title;
    string content;
    string priorty;
    Day *next;
    Day *prev;
    Day() : next(nullptr), prev(nullptr) {}
};

class Calendar
{
private:
    Day *head;

public:
    Calendar() : head(nullptr) {}

    void initCalendar(int totalDays = 30)
    {
        Day *dayOne = new Day();
        dayOne->dayNumber = 1;
        dayOne->title = "";
        dayOne->content = "";
        dayOne->priorty = "";
        dayOne->next = head;
        head = dayOne;

        Day *tail = head;
        for (int i = 2; i <= totalDays; i++)
        {
            Day *days = new Day();
            days->dayNumber = i;
            days->title = "";
            days->content = "";
            days->priorty = "";
            days->prev = tail;
            tail->next = days;
            tail = days;
        }
        tail->next = head;
        head->prev = tail;
    }

    void addEvent(int dayN)
    {
        Day *curr = head;
        
        while (true)
        {
            if (dayN == curr->dayNumber)
            {
                cout << "Gün bulundu: " << curr->dayNumber << endl;
                if (curr->title == "")
                {
                    string t, c, p;
                    cout << "Gün boş. Lütfen sırasıyla Title, Content ve Priority bilgilerini giriniz:" << endl;
                    cin >> t >> c >> p;
                    curr->title = t;
                    curr->content = c;
                    curr->priorty = p;
                    cout << "Etkinlik başarıyla eklendi." << endl;
                    return;
                }
                else
                {
                    cout << "Bu günde zaten bir etkinlik mevcut." << endl;
                }
            }
            else
            {
                curr = curr->next;
            }
           
        }
    }

    void changeEvent(int dayN)
    {
        Day *curr = head;
        
        while (true)
        {
            if (dayN == curr->dayNumber)
            {
                if (curr->title == "")
                {
                    cout << "Gün boş, yeni bir etkinlik eklenebilir." << endl;
                    string t, c, p;
                    cout << "Title, Content ve Priority bilgilerini giriniz:" << endl;
                    cin >> t >> c >> p;
                    curr->title = t;
                    curr->content = c;
                    curr->priorty = p;
                    return;
                }
                if (curr->title != "")
                {
                    cout << "Bu günde zaten bir etkinlik var." << endl;
                    cout << "Title: " << curr->title << " | Content: " << curr->content << " | Priority: " << curr->priorty << endl;
                    return;
                }
            }
            else
            {
                curr = curr->next;
            }
           
        }
    }

    void deleteEvent(int dayN)
    {
        Day *curr = head;
       
        while (true)
        {
            if (dayN == curr->dayNumber)
            {
                if (curr->title == "")
                {
                    cout << "Bu gün zaten boş!" << endl;
                    return;
                }
                if (curr->title != "")
                {
                    cout << "Aşağıdaki etkinlik siliniyor:" << endl;
                    cout << "Title: " << curr->title << " | Content: " << curr->content << " | Priority: " << curr->priorty << endl;
                    curr->title = "";
                    curr->content = "";
                    curr->priorty = "";
                    cout << "Etkinlik silindi." << endl;
                    return;
                }
            }
            else
            {
                curr = curr->next;
            }
          
        }
    }

    void listEvents(int dayN)
    {
        Day *curr = head;
        
        while (true)
        {
            if (curr->dayNumber == dayN)
            {
                bool quit = true;
                string secim;
                while (quit)
                {
                    cout << "Gün: " << curr->dayNumber
                         << " | Başlık: " << curr->title
                         << " | İçerik: " << curr->content
                         << " | Önem: " << curr->priorty
                         << " | (Önceki gün için: p, Sonraki için: n, Çıkış: q)" << endl;

                    cin >> secim;
                    if (secim == "q")
                    {
                        quit = false;
                        cout << "Listeden çıkış yapılıyor..." << endl;
                    }
                    if (secim == "p")
                    {
                        curr = curr->prev;
                    }
                    if (secim == "n")
                    {
                        curr = curr->next;
                    }
                }
                break;
            }
            else
            {
                curr = curr->next;
            }
           
        }
    }
};

int main()
{
    int secim = 5;
    bool x = true;
    int day = 0;
    Calendar calendar;
    calendar.initCalendar();

    while (x)
    {
        cout << "\nLütfen yapmak istediğiniz işlemi seçiniz:\n"
             << "1 - Etkinlik Ekle\n"
             << "2 - Etkinlik Düzenle\n"
             << "3 - Etkinlik Listele\n"
             << "4 - Etkinlik Sil\n"
             << "5 - Çıkış\n"
             << "Seçiminiz: ";
        cin >> secim;

        switch (secim)
        {
        case 1:
            cout << "Hangi güne etkinlik eklemek istiyorsunuz? (1-30 arası): ";
            cin >> day;
            if (day < 1 || day > 30)
            {
                cout << "Lütfen 1 ile 30 arasında bir sayı giriniz!" << endl;
                break;
            }
            calendar.addEvent(day);
            break;

        case 2:
            cout << "Hangi günün etkinliğini değiştirmek istiyorsunuz? (1-30 arası): ";
            cin >> day;
            if (day < 1 || day > 30)
            {
                cout << "Lütfen 1 ile 30 arasında bir sayı giriniz!" << endl;
                break;
            }
            calendar.changeEvent(day);
            break;

        case 3:
            cout << "Hangi günü listelemek istiyorsunuz? (1-30 arası): ";
            cin >> day;
            if (day < 1 || day > 30)
            {
                cout << "Lütfen 1 ile 30 arasında bir sayı giriniz!" << endl;
                break;
            }
            calendar.listEvents(day);
            break;

        case 4:
            cout << "Hangi günün etkinliğini silmek istiyorsunuz? (1-30 arası): ";
            cin >> day;
            if (day < 1 || day > 30)
            {
                cout << "Lütfen 1 ile 30 arasında bir sayı giriniz!" << endl;
                break;
            }
            calendar.deleteEvent(day);
            break;

        case 5:
            x = false;
            cout << "Programdan çıkılıyor..." << endl;
            break;

        default:
            cout << "Hatalı seçim! Lütfen geçerli bir işlem numarası girin." << endl;
            break;
        }
    }

    return 0;
}
