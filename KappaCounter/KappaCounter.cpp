#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <chrono>
#include <thread>
#include <algorithm>
#include <vector>


//using all the proper namespaces
using namespace std;
using namespace sf;
using namespace std::this_thread;    
using namespace std::chrono_literals; 
using std::chrono::system_clock;

int main()
{
    //gets the file
    ifstream file("..\\data\\100k.txt", ios::in);
    string line;

    //maps used for the purpose of the project to be compared
    unordered_map<float, string> mapUn;
    map<float, string> mapOr;

    float pos = 0;

    //saves each and every line into maps
    if (file.is_open()) {

        while (!file.eof()) {
            getline(file, line);
            mapOr[pos] = line;
            mapUn[pos] = line;
            pos++;
        }
    }

    //creates an visual window
    RenderWindow window(sf::VideoMode(1080,720), "");
    
    /**********************************************First Window and their variables**********************************************************************/
    Font fontTitle;
    Text textTitle;
    Text startButton;

    Font numbs;
    numbs.loadFromFile("..\\fonts\\LEMONMILK-Regular.otf");
    fontTitle.loadFromFile("..\\fonts\\SPEEDTRAP FREE.ttf");

    textTitle.setFont(fontTitle);
    startButton.setFont(fontTitle);

    textTitle.setString("Kappa Counter");
    textTitle.setCharacterSize(140);
    textTitle.setFillColor(sf::Color::White);
    textTitle.setStyle(sf::Text::Bold );
    textTitle.setPosition(130, 100);

    startButton.setString("START");
    startButton.setCharacterSize(100); 
    startButton.setFillColor(sf::Color::White);
    startButton.setStyle(sf::Text::Bold);
    startButton.setPosition(425, 400);

    bool startWindow = false;
    while (window.isOpen() && startWindow ==false)
    {
       sf::Event event;
       Vector2i mousePos = Mouse::getPosition(window);
       int x = mousePos.x;
       int y = mousePos.y;

        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        if (event.type == Event::MouseButtonPressed) {
            if (event.key.code == Mouse::Left) {
                if (x>425 && x<655 && y>430 && y<500) {

                    startWindow = true;
                }
            }
        }
        window.clear();
        window.draw(textTitle);
        window.draw(startButton);
        window.display();
    }
    /**********************************************End of First Window and their variables**********************************************************************/

    /************************************************Variables of the Second window****************************************************************/
    //title Resize
    textTitle.setCharacterSize(75);
    textTitle.setPosition(300, 50);

    //Get all the pictures into a texture
    Texture TriHard;
    TriHard.loadFromFile("..\\emotes\\TriHard.png");

    Texture kappa;
    kappa.loadFromFile("..\\emotes\\Kappa.png");

    Texture head;
    head.loadFromFile("..\\emotes\\4Head.png");

    Texture FeelsGoodMan;
    FeelsGoodMan.loadFromFile("..\\emotes\\FeelsGoodMan.png");

    Texture baby;
    baby.loadFromFile("..\\emotes\\BabyRage.png");

    Texture notLike;
    notLike.loadFromFile("..\\emotes\\notlikethis.png");

    Texture pogChamp;
    pogChamp.loadFromFile("..\\emotes\\pogChamp.png");

    Texture CoolCat;
    CoolCat.loadFromFile("..\\emotes\\CoolCat.png");

    Texture wutFace;
    wutFace.loadFromFile("..\\emotes\\wutFace.png");

    //sets all the emotes places and texture
    Sprite emote1;
    emote1.setTexture(TriHard);
    emote1.setPosition(50, 200);

    Sprite emote2;
    emote2.setTexture(kappa);
    emote2.setPosition(50, 300);

    Sprite emote3;
    emote3.setTexture(head);
    emote3.setPosition(50, 400);

    Sprite emote4;
    emote4.setTexture(FeelsGoodMan);
    emote4.setPosition(200, 200);

    Sprite emote5;
    emote5.setTexture(baby);
    emote5.setPosition(200, 300);

    Sprite emote6;
    emote6.setTexture(notLike);
    emote6.setPosition(200, 400);

    Sprite emote7;
    emote7.setTexture(pogChamp);
    emote7.setPosition(350, 200);

    Sprite emote8;
    emote8.setTexture(CoolCat);
    emote8.setPosition(350, 300);

    Sprite emote9;
    emote9.setTexture(wutFace);
    emote9.setPosition(350, 400);

    //This is the name of each emote place right below each image
    Text name1;
    name1.setString("TriHard");
    name1.setFont(fontTitle);
    name1.setCharacterSize(15);
    name1.setFillColor(sf::Color::White);
    name1.setPosition(50, 230);

    Text name2;
    name2.setString("Kappa");
    name2.setFont(fontTitle);
    name2.setCharacterSize(15);
    name2.setFillColor(sf::Color::White);
    name2.setPosition(50, 330);

    Text name3;
    name3.setString("FourHead");
    name3.setFont(fontTitle);
    name3.setCharacterSize(15);
    name3.setFillColor(sf::Color::White);
    name3.setPosition(50, 430);

    Text name4;
    name4.setString("FeelsGoodMan");
    name4.setFont(fontTitle);
    name4.setCharacterSize(15);
    name4.setFillColor(sf::Color::White);
    name4.setPosition(200, 230);

    Text name5;
    name5.setString("BabyRage");
    name5.setFont(fontTitle);
    name5.setCharacterSize(15);
    name5.setFillColor(sf::Color::White);
    name5.setPosition(200, 330);

    Text name6;
    name6.setString("NotLikeThis");
    name6.setFont(fontTitle);
    name6.setCharacterSize(15);
    name6.setFillColor(sf::Color::White);
    name6.setPosition(200, 430);

    Text name7;
    name7.setString("PogChamp");
    name7.setFont(fontTitle);
    name7.setCharacterSize(15);
    name7.setFillColor(sf::Color::White);
    name7.setPosition(350, 230);

    Text name8;
    name8.setString("CoolCat");
    name8.setFont(fontTitle);
    name8.setCharacterSize(15);
    name8.setFillColor(sf::Color::White);
    name8.setPosition(350, 330);

    Text name9;
    name9.setString("WutFace");
    name9.setFont(fontTitle);
    name9.setCharacterSize(15);
    name9.setFillColor(sf::Color::White);
    name9.setPosition(350, 430);

    //All text variables to make the chat follow along
    Text str1;
    str1.setString("");
    str1.setFont(fontTitle);
    str1.setCharacterSize(15);
    str1.setFillColor(sf::Color::White);
    str1.setPosition(50, 500);

    Text str2;
    str2.setString("");
    str2.setFont(fontTitle);
    str2.setCharacterSize(15);
    str2.setFillColor(sf::Color::White);
    str2.setPosition(50, 530);

    Text str3;
    str3.setString("");
    str3.setFont(fontTitle);
    str3.setCharacterSize(15);
    str3.setFillColor(sf::Color::White);
    str3.setPosition(50, 560);

    Text str4;
    str4.setString("");
    str4.setFont(fontTitle);
    str4.setCharacterSize(15);
    str4.setFillColor(sf::Color::White);
    str4.setPosition(50, 590);

    Text str5;
    str5.setString("");
    str5.setFont(fontTitle);
    str5.setCharacterSize(15);
    str5.setFillColor(sf::Color::White);
    str5.setPosition(50, 620);

    Text str6;
    str6.setString("");
    str6.setFont(fontTitle);
    str6.setCharacterSize(15);
    str6.setFillColor(sf::Color::White);
    str6.setPosition(50, 650);

    Text str7;
    str7.setString("");
    str7.setFont(fontTitle);
    str7.setCharacterSize(15);
    str7.setFillColor(sf::Color::White);
    str7.setPosition(50, 680);

    //Other Text variables to indicate whats going on
    Text timerOrdered;
    timerOrdered.setString("Ordered Map Time                                Seconds");
    timerOrdered.setFont(fontTitle);
    timerOrdered.setCharacterSize(50);
    timerOrdered.setFillColor(sf::Color::White);
    timerOrdered.setPosition(50, 500);

    Text timerUnordored;
    timerUnordored.setString("Unordered Map Time                            Seconds");
    timerUnordored.setFont(fontTitle);
    timerUnordored.setCharacterSize(50);
    timerUnordored.setFillColor(sf::Color::White);
    timerUnordored.setPosition(50, 600);

    Text ordoredActualTime;
    string timePrintOr;
    ordoredActualTime.setString("0");
    ordoredActualTime.setFont(numbs);
    ordoredActualTime.setCharacterSize(50);
    ordoredActualTime.setFillColor(sf::Color::White);
    ordoredActualTime.setPosition(650, 500);

    Text unordoredActualTime;
    string timePrintUn;
    unordoredActualTime.setString("0");
    unordoredActualTime.setFont(numbs);
    unordoredActualTime.setCharacterSize(50);
    unordoredActualTime.setFillColor(sf::Color::White);
    unordoredActualTime.setPosition(650, 600);

    //string that will be set to be compared to each string
    string kappaStr("Kappa");
    string triHardStr("TriHard");
    string headStr("4Head");
    string feelsGoodStr("FeelsGoodMan");
    string pogChampStr("PogChamp");
    string coolCatStr("CoolCat");
    string wutStr("WutFace");
    string babyStr("BabyRage");
    string notStr("NotLikeThis");

    //their counts to be updated as it runs
    int kappaI = 0;
    int triHardI = 0;
    int headI = 0;
    int feelsGoodI = 0;
    int pogCI = 0;
    int coolCatI = 0;
    int wutI = 0;
    int babyI = 0;
    int notI = 0;

    //the numeric text for SFML
    Text int1Text;
    string int1str;
    int1Text.setString("0");
    int1Text.setFont(numbs);
    int1Text.setCharacterSize(20);
    int1Text.setFillColor(sf::Color::White);
    int1Text.setPosition(100, 200);

    Text int2Text;
    string int2str;
    int2Text.setString("0");
    int2Text.setFont(numbs);
    int2Text.setCharacterSize(20);
    int2Text.setFillColor(sf::Color::White);
    int2Text.setPosition(100, 300);

    Text int3Text;
    string int3str;
    int3Text.setString("0");
    int3Text.setFont(numbs);
    int3Text.setCharacterSize(20);
    int3Text.setFillColor(sf::Color::White);
    int3Text.setPosition(100, 400);

    Text int4Text;
    string int4str;
    int4Text.setString("0");
    int4Text.setFont(numbs);
    int4Text.setCharacterSize(20);
    int4Text.setFillColor(sf::Color::White);
    int4Text.setPosition(250, 200);

    Text int5Text;
    string int5str;
    int5Text.setString("0");
    int5Text.setFont(numbs);
    int5Text.setCharacterSize(20);
    int5Text.setFillColor(sf::Color::White);
    int5Text.setPosition(250, 300);

    Text int6Text;
    string int6str;
    int6Text.setString("0");
    int6Text.setFont(numbs);
    int6Text.setCharacterSize(20);
    int6Text.setFillColor(sf::Color::White);
    int6Text.setPosition(250, 400);

    Text int7Text;
    string int7str;
    int7Text.setString("0");
    int7Text.setFont(numbs);
    int7Text.setCharacterSize(20);
    int7Text.setFillColor(sf::Color::White);
    int7Text.setPosition(400, 200);

    Text int8Text;
    string int8str;
    int8Text.setString("0");
    int8Text.setFont(numbs);
    int8Text.setCharacterSize(20);
    int8Text.setFillColor(sf::Color::White);
    int8Text.setPosition(400, 300);

    Text int9Text;
    string int9str;
    int9Text.setString("0");
    int9Text.setFont(numbs);
    int9Text.setCharacterSize(20);
    int9Text.setFillColor(sf::Color::White);
    int9Text.setPosition(400, 400);

    Text leaderTitle;
    leaderTitle.setString("Ordered Map Iteration");
    leaderTitle.setFont(fontTitle);
    leaderTitle.setCharacterSize(50);
    leaderTitle.setFillColor(sf::Color::White);
    leaderTitle.setPosition(550, 280);

    //variables to be used to auxiliate the iteration
    bool once = true;
    int ptr = 0;
    auto  final = 0;
    auto final2 = 0;
    int count = 0;

    /**********************************************End of variable Declaration**********************************************************************/

    /**********************************************Begin of the second screen**********************************************************************/

    while (window.isOpen() && startWindow)
    {
        sf::Event event;
       
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
  
        if (once) {
            auto startOr = chrono::steady_clock::now();
            //iterates through the ordered map
            for (auto it = mapOr.begin(); it != mapOr.end(); it++) {
                //runs in a block of 7 string to be printed in to the window and simulate a chat
                if (it->first <= mapOr.size() - 7) {
                    ptr = it->first;
                    str1.setString(mapOr[ptr].substr(27, mapOr[ptr].length()));
                    str2.setString(mapOr[ptr + 1].substr(27, mapOr[ptr + 1].length()));
                    str3.setString(mapOr[ptr + 2].substr(27, mapOr[ptr + 2].length()));
                    str4.setString(mapOr[ptr + 3].substr(27, mapOr[ptr + 3].length()));
                    str5.setString(mapOr[ptr + 4].substr(27, mapOr[ptr + 4].length()));
                    str6.setString(mapOr[ptr + 5].substr(27, mapOr[ptr + 5].length()));
                    str7.setString(mapOr[ptr + 6].substr(27, mapOr[ptr + 6].length()));
                }
                //if finds the string the it counts +1
                if (it->second.find(triHardStr) != string::npos) {
                    triHardI++;
                    int1str = to_string(triHardI);
                    int1Text.setString(int1str);
                    
                }

                if (it->second.find(kappaStr) != string::npos) {
                    kappaI++;
                    int2str = to_string(kappaI);
                    int2Text.setString(int2str);
                   
                }

                if (it->second.find(headStr) != string::npos) {
                    headI++;
                    int3str = to_string(headI);
                    int3Text.setString(int3str);
                    
                }

                if (it->second.find(feelsGoodStr) != string::npos) {
                    feelsGoodI++;
                    int4str = to_string(feelsGoodI);
                    int4Text.setString(int4str);
                    
                }

                if (it->second.find(babyStr) != string::npos) {
                    babyI++;
                    int5str = to_string(babyI);
                    int5Text.setString(int5str);
                    
                }

                if (it->second.find(notStr) != string::npos) {
                    notI++;
                    int6str = to_string(notI);
                    int6Text.setString(int6str);
                    
                }

                if (it->second.find(pogChampStr) != string::npos) {
                    pogCI++;
                    int7str = to_string(pogCI);
                    int7Text.setString(int7str);
                   
                }

                if (it->second.find(coolCatStr) != string::npos) {
                    coolCatI++;
                    int8str = to_string(coolCatI);
                    int8Text.setString(int8str);
                    
                }

                if (it->second.find(wutStr) != string::npos) {
                    wutI++;
                    int9str = to_string(wutI);
                    int9Text.setString(int9str);
                    
                }


                window.clear();

                window.draw(textTitle);
                window.draw(emote1);
                window.draw(emote2);
                window.draw(emote3);
                window.draw(emote4);
                window.draw(emote5);
                window.draw(emote6);
                window.draw(emote7);
                window.draw(emote8);
                window.draw(emote9);

                window.draw(int1Text);
                window.draw(int2Text);
                window.draw(int3Text);
                window.draw(int4Text);
                window.draw(int5Text);
                window.draw(int6Text);
                window.draw(int7Text);
                window.draw(int8Text);
                window.draw(int9Text);

                window.draw(name1);
                window.draw(name2);
                window.draw(name3);
                window.draw(name4);
                window.draw(name5);
                window.draw(name6);
                window.draw(name7);
                window.draw(name8);
                window.draw(name9);

                window.draw(leaderTitle);

                window.draw(str1);
                window.draw(str2);
                window.draw(str3);
                window.draw(str4);
                window.draw(str5);
                window.draw(str6);
                window.draw(str7);
                window.display();
            }
            auto endOr = chrono::steady_clock::now();
            //calculates the time it takes
            final = chrono::duration_cast<chrono::seconds>(endOr - startOr).count();          
        }

        sleep_for(1s);
        sleep_until(system_clock::now() + 1s);

        kappaI = 0;
        triHardI = 0;
        headI = 0;
        feelsGoodI = 0;
        pogCI = 0;
        coolCatI = 0;
        wutI = 0;
        babyI = 0;
        notI = 0;

        leaderTitle.setString("Unordered Map Iteration");
        leaderTitle.setPosition(500, 280);
        if (once) {
            auto startUn = chrono::steady_clock::now();
            //iteration for the unordered map
            for (auto it = mapUn.begin(); it != mapUn.end();it++) {
                //runs in a block of 7 string to be printed in to the window and simulate a chat
                if (it->first <= mapUn.size()-7) {
                    ptr = it->first;
                    str1.setString(mapUn[ptr].substr(27, mapUn[ptr].length()));
                    str2.setString(mapUn[ptr+1].substr(27, mapUn[ptr + 1].length()));
                    str3.setString(mapUn[ptr+2].substr(27, mapUn[ptr + 2].length()));
                    str4.setString(mapUn[ptr + 3].substr(27, mapUn[ptr + 3].length()));
                    str5.setString(mapUn[ptr + 4].substr(27, mapUn[ptr + 4].length()));
                    str6.setString(mapUn[ptr + 5].substr(27, mapUn[ptr + 5].length()));
                    str7.setString(mapUn[ptr + 6].substr(27, mapUn[ptr + 6].length()));
                }
               //if it find the string then it counts +1
                if (it->second.find(triHardStr) != string::npos) {
                    triHardI++;
                    int1str = to_string(triHardI);
                    int1Text.setString(int1str);
                }

                if (it->second.find(kappaStr) != string::npos) {
                    kappaI++;
                    int2str = to_string(kappaI);
                    int2Text.setString(int2str);
                }

                if (it->second.find(headStr) != string::npos) {
                    headI++;
                    int3str = to_string(headI);
                    int3Text.setString(int3str);
                }

                if (it->second.find(feelsGoodStr) != string::npos) {
                    feelsGoodI++;
                    int4str = to_string(feelsGoodI);
                    int4Text.setString(int4str);
                }

                if (it->second.find(babyStr) != string::npos) {
                    babyI++;
                    int5str = to_string(babyI);
                    int5Text.setString(int5str);
                }

                if (it->second.find(notStr) != string::npos) {
                    notI++;
                    int6str = to_string(notI);
                    int6Text.setString(int6str);
                }

                if (it->second.find(pogChampStr) != string::npos) {
                    pogCI++;
                    int7str = to_string(pogCI);
                    int7Text.setString(int7str);
                }

                if (it->second.find(coolCatStr) != string::npos) {
                    coolCatI++;
                    int8str = to_string(coolCatI);
                    int8Text.setString(int8str);
                }

                if (it->second.find(wutStr) != string::npos) {
                    wutI++;
                    int9str = to_string(wutI);
                    int9Text.setString(int9str);
                }
                window.clear();

                window.draw(textTitle);
                window.draw(emote1);
                window.draw(emote2);
                window.draw(emote3);
                window.draw(emote4);
                window.draw(emote5);
                window.draw(emote6);
                window.draw(emote7);
                window.draw(emote8);
                window.draw(emote9);

                window.draw(int1Text);
                window.draw(int2Text);
                window.draw(int3Text);
                window.draw(int4Text);
                window.draw(int5Text);
                window.draw(int6Text);
                window.draw(int7Text);
                window.draw(int8Text);
                window.draw(int9Text);

                window.draw(name1);
                window.draw(name2);
                window.draw(name3);
                window.draw(name4);
                window.draw(name5);
                window.draw(name6);
                window.draw(name7);
                window.draw(name8);
                window.draw(name9);
                
                window.draw(leaderTitle);

                window.draw(str1);
                window.draw(str2);
                window.draw(str3);
                window.draw(str4);
                window.draw(str5);
                window.draw(str6);
                window.draw(str7);
                window.display();
            }
            auto endUn = chrono::steady_clock::now();
            //final time of the second iteration
            final2 = chrono::duration_cast<chrono::seconds>(endUn - startUn).count(); 
 
        }
        once = false;
           
        leaderTitle.setString("Leaderboard");
        leaderTitle.setPosition(600, 150);

        timePrintOr = to_string(final); 
        ordoredActualTime.setString(timePrintOr);
        
        timePrintUn = to_string(final2);
        unordoredActualTime.setString(timePrintUn);

        window.clear();
        //all the variables drawn in the window
        window.draw(int1Text);
        window.draw(int2Text);
        window.draw(int3Text);
        window.draw(int4Text);
        window.draw(int5Text);
        window.draw(int6Text);
        window.draw(int7Text);
        window.draw(int8Text);
        window.draw(int9Text);

        window.draw(emote1);
        window.draw(emote2);
        window.draw(emote3);
        window.draw(emote4);
        window.draw(emote5);
        window.draw(emote6);
        window.draw(emote7);
        window.draw(emote8);
        window.draw(emote9);

        window.draw(name1);
        window.draw(name2);
        window.draw(name3);
        window.draw(name4);
        window.draw(name5);
        window.draw(name6);
        window.draw(name7);
        window.draw(name8);
        window.draw(name9);


        window.draw(timerUnordored);
        window.draw(timerOrdered);

        window.draw(unordoredActualTime);
        window.draw(ordoredActualTime);

        window.draw(textTitle);
        window.display();

       
    }

    /**********************************************End of second Window **********************************************************************/
    return 0;
}