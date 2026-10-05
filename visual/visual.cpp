/*本题目主要考查类的使用,不了解类的同学建议先去学习相关知识。

    背景介绍：在Robomaster比赛中，一个机器人在进行自瞄的时候有时会同时识别到多个敌方目标。此时机器人需要
    选择其中一个来作为最佳打击目标并进行打击。通常我们会锁定距离准心（操作手端的屏幕中心）最近的目标。
    示例    ————————————————————————————————————————————
            |                       T                  |
            |        H            (1,4)                |
            |      (-9,3)                              |         
            |                                          |
            |                     +                    |      此时应当锁定S目标
            |                S                         |
            |              (-3,1)                      |
            |                              I           |
            |                            (7,-3)        |
            ————————————————————————————————————————————

    题目：编写一个程序，记录4个敌方目标的二维坐标，锁定距离准心最近的目标并输出对应的兵种ID。
    
    要求：采用面向对象的方法，设计两个类：
    Enemy 类：包含敌人的坐标和兵种ID，以及相应的设置和获取函数。
    Target 类：包含一个 Enemy 类的对象数组，并具备选择并返回最佳打击目标和输出的功能。

    PS：获取输入数据的框架已经替各位实现好了，在对应的地方调用你们编写的设置函数即可。
*/

#include <bits/stdc++.h>
using namespace std;

// ==================== 在此处编写 Enemy和Target 类 ====================
class Enemy {
private:
    double _x;
    double _y;
    char _id;

public:
    Enemy() : _x(0), _y(0), _id('\0') {}

    void set(char id,double x,double y) {
        _id=id;
        _x=x;
        _y=y;
    }
    char getId() const {
        return _id;
    }
    double getX() const {
        return _x;
    }
    double getY() const {
        return _y;
    }
    double centerdistance() const {
        return _x*_x+_y*_y;
    }
};

class Target {
private:
    Enemy _enemies[4];

public:
    Enemy& getEnemy(int No_) {
        return _enemies[No_];
    }
    const Enemy& getEnemy(int No_) const {
        return _enemies[No_];
    }

    // 输出
    Enemy closestenemy() const {
        int bestNo_=0;
        double bestDistance=_enemies[0].centerdistance();

        for (int i=1; i<4; i++) {
            double distance = _enemies[i].centerdistance();
            if (distance<bestDistance) {
                bestDistance=distance;
                bestNo_=i;
            }
        }

        return _enemies[bestNo_];
    }

    // 输出
    void printbestenemy() const {
        cout << closestenemy().getId() << endl;
    }
};

// ====================================================================
//主函数
int main() {
    Target target;

    for (int i=0; i<4; i++) {
        double x,y;
        char id;
        cout<<"输入第 " <<i+1<<" 个目标的兵种ID和坐标x y: ";
        cin>>id>>x>>y;
        // 调用
        target.getEnemy(i).set(id, x, y);
    }
    // 调用
    target.printbestenemy();
    return 0;
}