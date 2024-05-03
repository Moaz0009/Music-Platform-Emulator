#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>
#include <unordered_set>

using namespace std;
//.......................................global.........................
vector<string>selected_data;

//string selected_song =selected_data[0];
//string selected_artist =selected_data[1];
//string selected_genre =selected_data[2];
//................................./
vector<string> genres;
vector<vector<string>> artistss;

//................................................................................
int no_users=0;
string genre[]={"POP","HIP-HOP", "ELECTRONIC","R&B", "ROCK","DRILL","COUNTRY","JAZZ","CLASSICAL","K-POP"};
string artists[10][5]={{"Amr Diab","Tamer Hossny","Angham","Dua Lipa","Ariana Grande"},
                      {"WEGZ","Marwan Moussa","Marwan Pablo","ABYSUIF","MOUSV"},
                      {"Avicii","Calvin Harris","The Chainsmokers","Zedd","Martin Garrix"},
                      {  "Beyoncé","Frank Ocean","The Weeknd","Rihanna","Usher" } ,
                      { "Cairokee","Slipknot","Black Sabbath","Tool","Mashrou' Leila"} ,
                      {"Ziad Zaza","Fivio Foreign","Headie One","Lil Durk","Chief Keef"} ,
                      {"Johnny Cash","Dolly Parton","Garth Brooks","Shania Twain","Luke Combs"},
                      {"Miles Davis","Ella Fitzgerald","John Coltrane","Louis Armstrong","Duke Ellington"},
                      {"Ludwig van Beethoven","Wolfgang Amadeus Mozart","Johann Sebastian Bach","Pyotr Ilyich Tchaikovsky","Claude Debussy"},
                      {"BTS","BLACKPINK","EXO","TWICE","GOT7"}};
                          // Pop
    std::string pop[5][5] = {
        // Amr Diab
        {"Nour El Ein", "Tamally Maak", "Osad Einy", "We Malo", "El Alem Allah"},
        // Tamer Hossny
        {"Nafs El Haneen", "Eish Besho'ak", "Ya Mali Aaeny", "Omry Ebtada", "Ana Mesh 3aref Atghayar"},
        // Angham
        {"Sidi Wesalak", "Rohy Feek", "Hala Khasa Gedan", "Omry Maak", "Mabatakhlafsh"},
        // Dua Lipa
        {"Don't Start Now", "Levitating", "New Rules", "Physical", "IDGAF"},
        // Ariana Grande
        {"Thank U, Next", "7 Rings", "Positions", "Into You", "God is a Woman"}
    };

    // Hip-Hop
    std::string hipHop[5][5] = {
        // WEGZ
        {"Ahlam", "Talat Daqat", "Wegz", "Ana Leek", "El Watan"},
        // Marwan Moussa
        {"Shaba", "Enta Maalem", "Lal Bokra", "Btal Hawa", "Ana"},
        // Marwan Pablo
        {"El Felous", "Taht El Yasmeen", "Marwan", "Ew3edny", "Rouhi"},
        // ABYSUIF
        {"Heddy Bobo", "Cool Boy", "ABYSUFI", "Dabedabedu", "Jovany"},
        // MOUSV
        {"Moudy", "Ashewa'k", "Oskot", "Hadid", "Awghal"}
    };

    // Electronic
    std::string electronic[5][5] = {
        // Avicii
        {"Wake Me Up", "Levels", "The Nights", "Hey Brother", "Waiting for Love"},
        // Calvin Harris
        {"Summer", "Feel So Close", "Slide", "Blame", "I Need Your Love"},
        // The Chainsmokers
        {"Closer", "Something Just Like This", "Paris", "Roses", "Don't Let Me Down"},
        // Zedd
        {"Clarity", "Stay", "Spectrum", "Beautiful Now", "Addicted to You"},
        // Martin Garrix
        {"Animals", "Scared to Be Lonely", "Break Through the Silence", "Ocean", "High on Life"}
    };

    // R&B
    std::string rnb[5][5] = {
        // Beyoncé
        {"Crazy In Love", "Irreplaceable", "Halo", "Love On Top", "Single Ladies"},
        // Frank Ocean
        {"Thinkin Bout You", "Lost", "Pink Matter", "Chanel", "Ivy"},
        // The Weeknd
        {"Blinding Lights", "Starboy", "Save Your Tears", "Can't Feel My Face", "The Hills"},
        // Rihanna
        {"Diamonds", "Stay", "Work", "Love on the Brain", "Only Girl (In the World)"},
        // Usher
        {"Yeah!", "OMG", "Love in This Club", "DJ Got Us Fallin' in Love", "Burn"}
    };

    // Rock
    std::string rock[5][5] = {
        // Cairokee
        {"Ya Abyad Ya Eswed", "El Keif", "Leilet El Omr", "Ma A'ad Saghir", "Sout El Horreya"},
        // Slipknot
        {"Psychosocial", "Before I Forget", "Duality", "Vermilion", "Dead Memories"},
        // Black Sabbath
        {"Paranoid", "Iron Man", "War Pigs", "N.I.B.", "Children of the Grave"},
        // Tool
        {"Schism", "Stinkfist", "46 & 2", "Lateralus", "Vicarious"},
        // Mashrou' Leila
        {"Fasateen", "Gharib Madi", "Aswan", "Abshar", "Sharmoofers"}
    };

    // Drill
    std::string drill[5][5] = {
        // Ziad Zaza
        {"Hate", "Summer", "Mosh Khatir", "Gamara", "100%"},
        // Fivio Foreign
        {"Big Drip", "Demons & Goblins", "Wetty", "Drive By", "Bop It"},
        // Headie One
        {"18HUNNA", "Know Better", "Princess Cuts", "Rubbery Bands", "Ain't It Different"},
        // Lil Durk
        {"Finesse Out The Gang Way", "Backdoor", "Hats Off", "3 Headed Goat", "Laugh Now Cry Later"},
        // Chief Keef
        {"Faneto", "Love Sosa", "I Don't Like", "Earned It", "3Hunna"}
    };

    // Country
    std::string country[5][5] = {
        // Johnny Cash
        {"Ring of Fire", "Hurt", "Folsom Prison Blues", "I Walk the Line", "Man in Black"},
        // Dolly Parton
        {"Jolene", "9 to 5", "Coat of Many Colors", "I Will Always Love You", "Here You Come Again"},
        // Garth Brooks
        {"Friends in Low Places", "The Dance", "Thunder Rolls", "If Tomorrow Never Comes", "Unanswered Prayers"},
        // Shania Twain
        {"Man! I Feel Like a Woman!", "You're Still the One", "That Don't Impress Me Much", "From This Moment On", "Any Man of Mine"},
        // Luke Combs
        {"Beautiful Crazy", "Hurricane", "Beer Never Broke My Heart", "Even Though I'm Leaving", "When It Rains It Pours"}
    };

    // Jazz
    std::string jazz[5][5] = {
        // Miles Davis
        {"So What", "Blue in Green", "All Blues", "Freddie Freeloader", "Flamenco Sketches"},
        // Ella Fitzgerald
        {"Summertime", "A-Tisket, A-Tasket", "Blue Skies", "Dream a Little Dream of Me", "Cry Me a River"},
        // John Coltrane
        {"Giant Steps", "My Favorite Things", "A Love Supreme", "Blue Train", "Naima"},
        // Louis Armstrong
        {"What a Wonderful World", "Hello, Dolly!", "Stardust", "When the Saints Go Marching In", "La Vie En Rose"},
        // Duke Ellington
        {"Take the A Train", "Mood Indigo", "It Don't Mean a Thing (If It Ain't Got That Swing)", "Sophisticated Lady", "Caravan"}
    };

    // Classical
    std::string classical[5][5] = {
        // Beethoven
        {"Symphony No. 5", "Moonlight Sonata", "Für Elise", "Symphony No. 9", "Piano Sonata No. 14"},
        // Mozart
        {"Eine kleine Nachtmusik", "Symphony No. 40", "Piano Sonata No. 16", "Requiem", "The Magic Flute"},
        // Bach
        {"Brandenburg Concertos", "Toccata and Fugue in D Minor", "Air on the G String", "Goldberg Variations", "Cello Suites"},
        // Tchaikovsky
        {"Swan Lake", "1812 Overture", "The Nutcracker Suite", "Romeo and Juliet Overture", "Symphony No. 6"},
        // Debussy
        {"Clair de Lune", "Prelude to the Afternoon of a Faun", "La Mer", "Arabesque No. 1", "Suite Bergamasque"}
    };

    // K-Pop
    std::string kpop[5][5] = {
        // BTS
        {"Dynamite", "Blood Sweat & Tears", "Boy With Luv", "DNA", "Fire"},
        // BLACKPINK
        {"DDU-DU DDU-DU", "Kill This Love", "How You Like That", "Lovesick Girls", "BOOMBAYAH"},
        // EXO
        {"Growl", "Love Shot", "Monster", "Tempo", "Ko Ko Bop"},
        // TWICE
        {"What is Love?", "Fancy", "Feel Special", "LIKEY", "Cheer Up"},
        // GOT7
        {"Just Right", "Hard Carry", "Lullaby", "Fly", "You Are"}
    };

class user_info
{
private:

    int no_of_genre;


    string user_name;
    string user_password;
    struct genre
    {
        string genre_name;
        int genre_index;
        genre *next_genre;
    };
   struct liked_song
    {
        string songg_name;
        string arti_name;
        string arti_genre;
        liked_song *next_liked_song;
        liked_song *prev_liked_song;};
    struct artist
    {
        string art_name;
        string art_genre;
        int art_index;
        int art_genr_index;
        artist* next_artist;
    };
    artist *f_art;
    genre *f_gen;
    liked_song *f_liked_song;



    unordered_map<string, vector<string>> playlists;// manage playlists

    unordered_map<string, unordered_map<string, unordered_set<string>>> music_data;// recommendations

public:

//yasmeen
   void load_music_data(const std::string& file_path) {
  std::ifstream file(file_path);
  if (!file.is_open()) {
    std::cerr << "Failed to open file: " << file_path << std::endl;
    return;
  }
string line;
  std::string genre;
  std::string artist;
  std::string song;

  while (std::getline(file, line)) {
    // Skip empty lines
    if (line.empty()) {
      continue;
    }

    // Check for genre line (assuming genres don't have spaces)
    if (line.find(' ') == std::string::npos) {
      genre = line;
    } else {
      // Artist and song extraction (assuming artist-song pairs separated by spaces)
      std::istringstream iss(line);
      if (iss >> artist) {
        while (iss >> song) {
          music_data[genre][artist].insert(song);
        }
      }
    }
  }

  file.close();
}



        void show_recommend_music(const vector<string>& genres, const vector<vector<string>>& artistss) {
            load_music_data("data base for music.txt");
        for (size_t i = 0; i < genres.size(); ++i) {
            cout << "Recommended songs for fans of " << genres[i] << " genre: " << endl;
            for (const auto& artist : artistss[i]) {
                if (1){//music_data[artist]["Genres"].count(genres[i])) {
                    int counter = 1;
                    for (const auto& song : music_data[artist]["Songs"]) {
                        if (counter > 5) {
                            break;
                        }
                        cout << "  " << counter << ". " << song << endl;
                        counter++;
                    }
                }
            }
        }}

   void recommend_music(const vector<string>& genres, const vector<vector<string>>& artistss,int song_number) {

        // Find the selected song based on the number
        int current_song_number = 1;
 cout<<5;
        for (size_t i = 0; i < genres.size(); ++i) {
                cout<<5;
            for (const auto& artist : artistss[i]) {
                if (1)//music_data[artist]["Genres"].count(genres[i])) {
                    {for (const auto& song : music_data[artist]["Songs"]) {
                       cout<<6;
                        if (current_song_number == song_number) {
                            cout<<7;
                            selected_data[0]=song;
                            cout<<song;
                            cout<<artist;
                            cout<<genres[i];
                            selected_data[1]=artist;
                            selected_data[2]=genres[i];
                            break;
                        }
                        current_song_number++;
                    }
                }
            }
        }

    }

string find_song_name(int song_index)
{artist* temp=f_art;
    double art_index=song_index/3.0;
    art_index=ceil(art_index);
    art_index--;//to make it an index
    (int) art_index;

   song_index=song_index-(3*art_index)-1;//to make it an index
   int c=0;

   while(c!=art_index)
   {
       temp=temp->next_artist;
       c++;
   }
    switch (temp->art_genr_index)
    {
    case 0:
            return pop[temp->art_index][song_index];

    break;
     case 1:
           return hipHop[temp->art_index][song_index];

    break;
    case 2:
            return electronic[temp->art_index][song_index];


    break;
    case 3:


            return rnb[temp->art_index][song_index];


    break;
     case 4:
            return rock[temp->art_index][song_index];


    break;
    case 5:


            return drill[temp->art_index][song_index];


    break;
    case 6:

        return country[temp->art_index][song_index];


    break;
    case 7:

        return jazz[temp->art_index][song_index];


    break;
    case 8:

            return classical[temp->art_index][song_index];

    break;
    case 9:
         return kpop[temp->art_index][song_index];


    break;
    }
}
// hadeeer
    bool m_playlists() {
        int option;
        while(1){
        const int num_options = 4;
        string options[num_options] = {
                "Create Playlist",
                "Add Song to Playlist",
                "show Playlists",
                "Go back\n"
        };
       cout<<"\n";
        for (int i = 0; i < num_options; ++i) {
            cout << i + 1 <<"-"<< options[i] << endl;
        }
         cout << "Your choice: " ;
        cin >> option;
        while(option<1||option>4)
        {
            cout<<"\nInvalid choice, try again!\n";
              cout << "Your choice: " ;
               cin >> option;
        }

        switch (option) {
            case 1:{
                vector<string> songs;
                string playlist_name;
                cout << "Enter playlist name: ";
                cin >> playlist_name;
                show_ava_songs();

                    while(1){
                cout<<"\n1-Add a song            2-Go back\n";
                cout<<"Your choice: ";
                cin>>option;
                while(option<1||option>2)
                {
                     cout<<"\n Invalid choice, try again!\n";
                       cout<<"\n1-Add a song            2-Go back\n";
                       cout<<"Your choice: ";
                       cin>>option;
                }
                if(option==2)
                { create_playlist(playlist_name, songs);
                    break;
                }
                cout << "Enter song number: ";
                cin>>option; //song number
              songs.push_back(  find_song_name(option));
                    }}
            break;
            case 2:{
                vector<string> songs;
                string  song,playlist_name;
                int playlist_number;
                show_playlists();
                cout << "\nChoose a playlist: ";
                cin >> playlist_number;
                int g=1;
                for (const auto& pair : playlists) {
                  if(g==playlist_number)
                  {
                      playlist_name=pair.first;
                      break;
                  }
                  g++;
                  }

                show_ava_songs();
                while(1){
                cout<<"\n1-Add a song            2-Go back\n";
                cout<<"Your choice: ";
                cin>>option;
                while(option<1||option>2)
                {
                     cout<<"\n Invalid choice, try again!\n";
                       cout<<"\n1-Add a song            2-Go back\n";
                       cout<<"Your choice: ";
                       cin>>option;
                }
                if(option==2)
                {   add_to_playlist(playlist_name, song);
                    break;
                }
                cout << "Enter song number: ";
                cin>>option; //song number
              songs.push_back(  find_song_name(option));

                }}

          break;
            case 3:
                show_playlists();
                break;

            case 4:
                return false;
                break;

        }
    }





    }

    void create_playlist(const string& playlist_name, const vector<string>& songs) {
        playlists[playlist_name] = songs;
        cout << "Playlist '" << playlist_name << " created successfully" << endl;
    }

    void add_to_playlist(const string& playlist_name, const string& song) {
        playlists[playlist_name].push_back(song);
        cout << "'" << song << " added to playlist " << playlist_name << endl;
    }

    void remove_from_playlist(const string& playlist_name, const string& song) {
        auto& playlist = playlists[playlist_name];
        auto it = find(playlist.begin(), playlist.end(), song);
        if (it != playlist.end()) {
            playlist.erase(it);
            cout << "'" << song << " removed from playlist " << playlist_name <<  endl;
        } else {
            cout << "'" << song << "not found in playlist " << playlist_name << endl;
        }
    }

    void show_playlists() {
        int cnt=1;
        cout << "\nAvailable playlists:\n" << endl;
        for (const auto& pair : playlists) {
            cout <<cnt<<"-"<<  pair.first << endl;
            cnt++;
        }
        cout<<"\n";
    }

     int no_of_artist;
     int no_of_liked_songs;
     user_info()
    {
        next_user=NULL;
        f_art=NULL;
        f_gen=NULL;
       f_liked_song=NULL;
        no_of_liked_songs=0;
        no_of_artist=0;
        no_of_genre=0;
    }
    user_info *next_user;
    string get_user_name()
    {
       return user_name;
    }
    artist* get_f_artist()
    {
        return f_art;
    }

    string get_user_password()
    {
        return user_password;
    }

    void sign_up()
    {
        cout<<"UserName: ";
        cin>>user_name;
        cout<<"Password: ";
        cin>>user_password;
    }
    void add_genre(string genre_name,int genre_index)
    {
        if(no_of_genre==0)
        {no_of_genre=1;
        genre *node=new genre;
        node->genre_name=genre_name;
        node->genre_index=genre_index;
        node->next_genre=NULL;
        f_gen=node;
        }
        else
        { no_of_genre++;
        genre *node=new genre;
        node->genre_name=genre_name;
        node->genre_index=genre_index;
        node->next_genre=NULL;
        genre *temp=f_gen;
        while(temp->next_genre!=NULL)
        {
            temp=temp->next_genre;
        }
        temp->next_genre=node;

        }

    }

    bool favorite_song(){
        int choice;
               if (no_of_liked_songs==0)
           {
               cout<<"\n*********** You don't have any favorite songs yet, let's Add some!************\n"<<"\n\n";
               show_ava_songs();
               again3: cout <<"\n1-Add a song             2-Go back \n";
               again2:cout <<"Your choice: ";
                cin>>choice;
                  while (choice>2||choice<1)
                  {
                    cout<<"Invalid Choice, try again \n";
                     cout <<"Your choice: ";
                     cin>>choice;
                  }
                  if(choice==1)
                  {
                       cout<<"Song number: ";
                     cin>>choice;
             again4:
               while (choice  > (no_of_artist*3)||choice<1)
               {
                   cout<<"Invalid Choice, try again \n";
                   cout<<"Song number:";
                   cin>>choice;
               }
             add_liked_song(choice);
               no_of_liked_songs++;
               goto again3;
               }
               else
               {
                return false;
               }


           }
           else
           { cout<<"\n*************Your favorite songs*******************\n";
              show_fav_songs();
              cout <<"\n1-Add a song             2-Go back \n";
              cout <<"Your choice: ";
                cin>>choice;
                while(choice<1 ||choice>2)
                {
                     cout<<"Invalid Choice, try again \n";
                     cout <<"Your choice: ";
                     cin>>choice;
                }
                if(choice==1)
                {show_ava_songs();
                           cout<<"\nSong number: ";
                            cin>>choice;
                            goto again4;
                }
                else
                {
                   return false;
                }


           }}





    void add_artist (string artist_name, string genre_name,int artist_index,int artist_genr_index)
    {
        if(no_of_artist==0)
        {no_of_artist=1;
        artist *node=new artist;
        node->art_name=artist_name;
        node->art_genre=genre_name;
        node->art_index=artist_index;
         node->art_genr_index=artist_genr_index;
        node->next_artist=NULL;
        f_art=node;
        }
        else{
        no_of_artist++;
        artist *node=new artist;
        node->art_name=artist_name;
        node->art_genre=genre_name;
        node->art_index=artist_index;
        node->art_genr_index=artist_genr_index;
        node->next_artist=NULL;
        artist *temp=f_art;
        while(temp->next_artist!=NULL)
        {
            temp=temp->next_artist;
        }
        temp->next_artist=node;
    }}
    void show_ava_songs()
{
    artist* temp=f_art;
    int m=1;
    while(temp!=NULL){
            int c=0;
    switch (temp->art_genr_index)
    {
    case 0:
        while (c<3)
        {
            cout<<m<<"-"<<pop[temp->art_index][c]<<", by "<< temp->art_name<<" - "<<temp->art_genre<<"\n";
            c++;
            m++;
        }
    break;
     case 1:
        while (c<3)
        {
            cout<<m<<"-"<<hipHop[temp->art_index][c]<<", by "<< temp->art_name<<" - "<<temp->art_genre<<"\n";
            c++;
            m++;
        }
    break;
    case 2:
        while (c<3)
        {
            cout<<m<<"-"<<electronic[temp->art_index][c]<<", by "<< temp->art_name<<" - "<<temp->art_genre<<"\n";
            c++;
            m++;
        }
    break;
    case 3:
        while (c<3)
        {
            cout<<m<<"-"<<rnb[temp->art_index][c]<<", by "<< temp->art_name<<" - "<<temp->art_genre<<"\n";
            c++;
            m++;
        }
    break;
     case 4:
        while (c<3)
        {
            cout<<m<<"-"<<rock[temp->art_index][c]<<", by "<< temp->art_name<<" - "<<temp->art_genre<<"\n";
            c++;
            m++;
        }
    break;
    case 5:
        while (c<3)
        {
            cout<<m<<"-"<<drill[temp->art_index][c]<<", by "<< temp->art_name<<" - "<<temp->art_genre<<"\n";
            c++;
            m++;
        }
    break;
    case 6:
        while (c<3)
        {
            cout<<m<<"-"<<country[temp->art_index][c]<<", by "<< temp->art_name<<" - "<<temp->art_genre<<"\n";
            c++;
            m++;
        }
    break;
    case 7:
        while (c<3)
        {
            cout<<m<<"-"<<jazz[temp->art_index][c]<<", by "<< temp->art_name<<" - "<<temp->art_genre<<"\n";
            c++;
            m++;
        }
    break;
    case 8:
        while (c<3)
        {
            cout<<m<<"-"<<classical[temp->art_index][c]<<", by "<< temp->art_name<<" - "<<temp->art_genre<<"\n";
            c++;
            m++;
        }
    break;
    case 9:
        while (c<3)
        {
            cout<<m<<"-"<<kpop[temp->art_index][c]<<", by "<< temp->art_name<<" - "<<temp->art_genre<<"\n";
            c++;
            m++;
        }
    break;
    }
    temp=temp->next_artist;
}}

    void remove_artist(int artist_no)
    {
        if(no_of_artist==0)
        {
            cout<<"Your Artists list is already empty!";
        }
        else if (artist_no==no_of_artist)
        {
            no_of_artist--;
            artist *temp=f_art;
            while(temp->next_artist->next_artist!=NULL)
            {
                temp=temp->next_artist;
            }
            delete(temp->next_artist);
           temp->next_artist=NULL;
        }
        else if(artist_no >0 && artist_no<no_of_artist-1)
        {
            artist *temp=f_art;
            artist *temp1=temp->next_artist;
            for (int i=0;i<artist_no-1;i++)
            {
                temp=temp->next_artist;
                temp1=temp->next_artist;
            }
            temp->next_artist=temp1->next_artist;
            delete(temp1);


        }
    }
    void show_sugg_artist(int k)
    {
        genre *temp=f_gen;
        int f=1;
        while(temp!=NULL)
        {  int c=0;
           while(c<k)
        {
           cout<<f<<"-"<<artists[temp->genre_index][c]<<"\n";
           c++;
           f++;
           }

           temp=temp->next_genre;
        }
    }
    void show_fav_songs()
{
    liked_song* current_song=f_liked_song;
    int cot=1;
    while(current_song!=NULL)
    {
        cout<<cot<<"-"<<current_song->songg_name<<", by "<<current_song->arti_name<<" - "<<current_song->arti_genre<<"\n";
        current_song=current_song->next_liked_song;
        cot++;}
}
bool show_profile()
{
    cout<<"\nUsername: "<<user_name<<"\n\n";
    cout<<"\n**Favorite Artists**\n";
    show_artist();
    cout<<"\n**Liked Songs**\n";
    show_fav_songs();
    cout<<"\n**Playlists**\n";
    show_playlists();
}

    bool play_song()
    {int choice;

    if(no_of_liked_songs==0)
    {
        cout<<"\nNo favorite songs to play from, Choose some first!\n";
        cout<<"1-Go back \n"<<"Your choice: ";
        cin>>choice;
        while(choice!=1)
        {
            cout<<"\nInvalid choice, try again!\n";
              cout<<"1-Go back \n"<<"Your choice: ";
              cin>>choice;

        }
        return false;
    }
   cout<<"\n*Playing from your favorites\n";
   liked_song* current_song=f_liked_song;
   playagain:
   cout<<"\nPlaying: "<<current_song->songg_name<<", by "<<current_song->arti_name<<"\n";
   cout<<"1-Next song             2-Prev song\n"<<"3-Go back"<<"\nYour choice: ";
   cin>>choice;
   if(choice==3)
   {
       return false;
   }
   else if(choice==1)
   {
       if(current_song-> next_liked_song==NULL)
      {
        cout<<"No Next songs available!\n";
        goto playagain;
      }
     current_song=current_song-> next_liked_song;
     goto playagain;
    }
    else if(choice==2)
    {  if(current_song-> prev_liked_song==NULL)
      {
        cout<<"No Previous songs available!\n";
        goto playagain;
      }
    current_song=current_song-> prev_liked_song;
     goto playagain;
    }}

    void start_add_liked_songs(string song_name,string art_name,string art_genre)
    {
        no_of_liked_songs++;
   liked_song* new_fav_song=new liked_song;
   //adding the new song node to the list
    new_fav_song->next_liked_song = NULL;
    new_fav_song->prev_liked_song = NULL;
    if (f_liked_song == NULL) {
        // If the list is empty, make the new node the head
        f_liked_song = new_fav_song;
    } else {
        // Traverse to the end of the list
        liked_song* temp = f_liked_song;
        while (temp->next_liked_song != NULL) {
            temp = temp->next_liked_song;
        }

        // Add the new node to the end of the list
        temp->next_liked_song = new_fav_song;
        new_fav_song->prev_liked_song = temp;
        new_fav_song->songg_name=song_name;;
        new_fav_song->arti_name=art_name;
        new_fav_song->arti_genre=art_genre;
    }
    }




  void add_liked_song(int song_index)
{ no_of_liked_songs++;
   artist* temp=f_art;
   liked_song* new_fav_song=new liked_song;
   //adding the new song node to the list
    new_fav_song->next_liked_song = NULL;
    new_fav_song->prev_liked_song = NULL;
    if (f_liked_song == NULL) {
        // If the list is empty, make the new node the head
        f_liked_song = new_fav_song;
    } else {
        // Traverse to the end of the list
        liked_song* temp = f_liked_song;
        while (temp->next_liked_song != NULL) {
            temp = temp->next_liked_song;
        }

        // Add the new node to the end of the list
        temp->next_liked_song = new_fav_song;
        new_fav_song->prev_liked_song = temp;
    }
   double art_index=song_index/3.0;
    art_index=ceil(art_index);
    art_index--;//to make it an index
    (int) art_index;

   song_index=song_index-(3*art_index)-1;//to make it an index
   int c=0;

   while(c!=art_index)
   {
       temp=temp->next_artist;
       c++;
   }
    switch (temp->art_genr_index)
    {
    case 0:
            new_fav_song->songg_name=pop[temp->art_index][song_index];
            new_fav_song->arti_name=temp->art_name;
            new_fav_song->arti_genre=temp->art_genre;
    break;
     case 1:
            new_fav_song->songg_name=hipHop[temp->art_index][song_index];
            new_fav_song->arti_name=temp->art_name;
            new_fav_song->arti_genre=temp->art_genre;
    break;
    case 2:
            new_fav_song->songg_name=electronic[temp->art_index][song_index];
            new_fav_song->arti_name=temp->art_name;
            new_fav_song->arti_genre=temp->art_genre;

    break;
    case 3:


            new_fav_song->songg_name=rnb[temp->art_index][song_index];
            new_fav_song->arti_name=temp->art_name;
            new_fav_song->arti_genre=temp->art_genre;

    break;
     case 4:
            new_fav_song->songg_name=rock[temp->art_index][song_index];
            new_fav_song->arti_name=temp->art_name;
            new_fav_song->arti_genre=temp->art_genre;

    break;
    case 5:


            new_fav_song->songg_name=drill[temp->art_index][song_index];
            new_fav_song->arti_name=temp->art_name;
            new_fav_song->arti_genre=temp->art_genre;

    break;
    case 6:

            new_fav_song->songg_name=country[temp->art_index][song_index];
            new_fav_song->arti_name=temp->art_name;
            new_fav_song->arti_genre=temp->art_genre;

    break;
    case 7:

            new_fav_song->songg_name=jazz[temp->art_index][song_index];
            new_fav_song->arti_name=temp->art_name;
            new_fav_song->arti_genre=temp->art_genre;

    break;
    case 8:

            new_fav_song->songg_name=classical[temp->art_index][song_index];
            new_fav_song->arti_name=temp->art_name;
            new_fav_song->arti_genre=temp->art_genre;
    break;
    case 9:
           new_fav_song->songg_name=kpop[temp->art_index][song_index];
            new_fav_song->arti_name=temp->art_name;
            new_fav_song->arti_genre=temp->art_genre;

    break;
    }

}


    bool add_art_main()
    {   int choice;
        cout<<"\n***********Adding a new favorite Artist***************\n";
         show_sugg_artist(5);
         int art_index;
        while(1){
                cout<<"\n1-Add an Artist               2-Go back\n"<<"Your choice: ";
                cin>>choice;
                while(choice>2 || choice<1)
                {
                    cout<<"\nInvalid choice, try again!\n";
                    cout<<"\n1-Add an Artist               2-Go back\n"<<"Your choice: ";
                    cin>>choice;
                }
                if(choice==1)
                    {
                cout<<"Artist Number: ";
                cin>>choice;
                while(choice<1 || choice>15)
                {
                    cout<<"Invalid Choice, Please try again.\n";
                     cout<<"Artist Number: ";
                    cin>>choice;
                }
                int genre_indexx;
               float genr_index=ceil(choice/5.0)-1;
               genre_indexx=genr_index;
               art_index=choice-((genr_index)*5)-1;
            genre* temp= f_gen;
               while(genr_index>0)
               {
                  temp=temp->next_genre;
                  genr_index--;
               }
               add_artist(artists[temp->genre_index][art_index],temp->genre_name,art_index,temp->genre_index);
              // artistss[genre_indexx].push_back(artists[temp->genre_index][art_index]);
     }
    else
    {
        return false;
    }}}
    void show_artist()
    {
    int cnt=1;
        artist *temp=f_art;
        while(temp!=NULL)
        {
            cout<<cnt<<"-"<<temp->art_name<<"   "<<temp->art_genre<<"\n";
temp=temp->next_artist;
            cnt++;
        }
    }

void show_genre()
{
   int cnt=1;
    genre *temp=f_gen;
    while(temp!=NULL)
    {
        cout<<cnt<<"-"<<temp->genre_name<<"\n";
        temp=temp->next_genre;
        cnt++;
    }
}
};
user_info *f_user=NULL;

bool user_name_ava(string user_n)
{
    user_info *temp=f_user;
    while(temp!=NULL)
    {
        if((temp->get_user_name())== user_n)
        {
            return false; // the user name exists
        }
        temp=temp->next_user;
    }
    return true; // new user name
}
bool user_pass_ava(string user_n,string user_p)
{
    user_info *temp=f_user;
    while(temp!=NULL)
    {
        if((temp->get_user_name())== user_n)
        {
            if(temp->get_user_password()==user_p)
                return true;
            else
                return false;
        }
        temp=temp->next_user;
    }
    return false;
}

void show_main_page()
{   cout<<"\n*********************** Home Page **********************************\n";
    cout<<"1-Manage your Play-lists"<<"------------"<<"2-Play a song\n";
    cout<<"--------------------------------------------------------\n";
    cout<<"3-Check your favorite songs"<<"----------"<<"4-Your profile\n";
    cout<<"--------------------------------------------------------\n";
    cout<<"5-Add a favorite Artist"<<"--------------"<<"6-Sign out\n";
    cout<<"--------------------------------------------------------\n";
    cout<<"Your Choice: ";
}

void add_user( user_info* new_userr)
{

    if(f_user==NULL)
    {
        f_user=new_userr;
    }
    else
    {
         user_info* temp=f_user;
         while(temp->next_user!=NULL)
         {
             temp=temp->next_user;
         }
         temp->next_user=new_userr;
    }
}


//////////////////////////////////////////////////////////

void show_ava_genre()
{ int arraySize = sizeof(genre) / sizeof(genre[0]);
    for (int i=0;i<(arraySize/2);i++)
    {
        cout<<i+1<<"-"<<genre[i]<<"             "<<i+6<<"-"<<genre[i+5]<<"\n";
    }
}
user_info* find_current_user(string user_name)
{
    user_info *temp=f_user;
    while(temp!=NULL)
    {
        if((temp->get_user_name())== user_name)
        {
            return temp;
        }
        temp=temp->next_user;
    }
    return NULL;
}


bool main_page(user_info* current_user) ///////main page function
{  int choice;
   mainpage:  show_main_page();
           cin>>choice;
           if(choice==3)
       {
            while(current_user->favorite_song());
            goto mainpage;
          }

         else  if(choice==6)//sign out
           {
               return true;
           }
           else if(choice==2)
           {
               while(current_user->play_song());
               goto mainpage;
           }
           else if(choice==1) //playlist option
           { while(current_user->m_playlists());
            goto mainpage;
           }
           else if(choice==4)
           {
               current_user->show_profile();
               cout<<"\n1-Go back\n";
               cout<<"Your choice: ";
               cin>>choice;
               while(choice!=1)
               {
                   cout<<"Invalid choice, try again!\n";
                   cout<<"Your choice: ";
                   cin>>choice;
               }
               goto mainpage;
           }
           else if(choice==5)
           {
               while(current_user->add_art_main());
               goto mainpage;
           }
           else
           {
               cout<<"\nInvalid choice, try again!\n";
                goto mainpage;
           }


}





int main()
{

    int choice;
 string user_name;
 string password;
 int genr[3];
 intialstart:
 cout<<"\n*******Welcome to Your Music Platform*********\n";
        cout<<"\n1- Sign in\n"<<"2- Sign up\n";
        cout<<"\nYour Choice: ";
        cin>>choice;
        if(choice==1)
        {  if(no_users==0)
        {
            cout<<"Sorry but there is no registered users yet\n";
            cout<<"Let's sing up instead!\n";
            goto signup;
        }
            resign:
            cout<<"Username: " ;
            cin>> user_name;
            cout<<"Password: ";
            cin>>password;
            if(user_name_ava(user_name))
            { cout<<"The Username or Password is not correct, please try again!\n";
            goto resign;
            }
            else
            {
                if(user_pass_ava(user_name,password))
                {
                    cout<<"Login Successfully.\n"<< "Welcome, "<<user_name<<"\n";
                    if(main_page(find_current_user(user_name)))
                    {
                        goto intialstart;
                    }
                }
                else
                {
                    cout<<"The Username or Password is not correct, please try again!\n";
               goto resign;
                }
            }
        }
        else if(choice==2)
        {  signup:
          user_info *new_user=new user_info;

           tryagain:
                new_user->sign_up();
            if(!user_name_ava(new_user->get_user_name()))
            {
               cout<<"Sorry this Username is Already taken, try another one!\n";
                goto tryagain;
            }
                if(no_users==0 )
                {
                    f_user=new_user;
                }
                else{
                add_user(new_user);}
            no_users++;


            cout<<"\n********Let's setup your account*********\n";
            cout<<"\n*********Choose 3 Music genres you like***********\n";
            show_ava_genre();

            int f=0;
            while(f<3)
            {  genag:
                cout<<"Genre Number: ";
                cin>>genr[f];
                genr[f]--;
                if( (genr[f]) <0 || (genr[f]) >9)
                {
                    cout<<"Invalid Choice, Please enter the Genre number\n";
                    goto genag;
                }
                new_user->add_genre(genre[(genr[f])],((genr[f])));
            //   genres.push_back(genre[(genr[f])]);

               // artistss.push_back(vector<string>());

                f++;
            }
        cout<<"\n*********************************************\n";
            cout<<"\n********Choose 5 Artists you like!***********\n";
            new_user->show_sugg_artist(3);
            f=0;
            while(f<5)
            {  rein:
                cout<<"Artist Number: ";
                cin>>choice;
                if(choice<1 || choice>9)
                {
                    cout<<"Invalid Choice, Please try again.\n";
                    goto rein;
                }
                if(choice<4) //genr[0]
                {
                     new_user->add_artist(artists[genr[0]][choice-1],genre[genr[0]],choice-1,genr[0]);
                  //   artistss[0].push_back(artists[genr[0]][choice-1]);
                }
                else if(choice<7) //genr[1]
                {
                     new_user->add_artist(artists[genr[1]][choice-4],genre[genr[1]],choice-4,genr[1]);
                   //  artistss[1]. push_back(artists[genr[1]][choice-4]);
                }
                else{
                     new_user->add_artist(artists[genr[2]][choice-7],genre[genr[2]],choice-7,genr[2]);
                  //   artistss[2]. push_back(artists[genr[2]][choice-7]);
                }
                f++;
            }
           /* cout<<"\n********Based on your chosen artists, we recommend these songs********\n";
            cout<<"\n********Let's add some to your favorites!*******\n";

            new_user->show_recommend_music(genres,artistss);
           int g=1;
           while(g==1){
            cout<<"\n1-Add a song         2-Skip\n";
            cout<<"Your choice: ";
            cin>>choice;
            while(choice>2||choice<1)
            {
                cout<<"\nInvalid choice, try again!\n";
                cout<<"Your choice: ";
                 cin>>choice;
            }
            if(choice==2)
              {g=0;}
            else
            {
            cout<<"Song number: ";
            cin>>choice;
            while(choice<1||choice>25)
            {
                 cout<<"\nInvalid choice, try again!\n";
                  cout<<"Song number: ";
                  cin>>choice;
            }

            new_user->  recommend_music(genres,artistss,choice);
            new_user->start_add_liked_songs(selected_data[0],selected_data[1], selected_data[2]);
}}*/
           cout<<"\n************************************\n";
           cout<<"You're All Done!\n"<<"Welcome, "<<new_user->get_user_name()<<"\n";
           if(main_page(new_user))
                    {
                        goto intialstart;
                    }

        }


        }
