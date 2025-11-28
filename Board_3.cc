export module Board;
import <iostream>;
import <vector>;
import <memory>;
import <string>;
import Link;
using namespace std;


export struct Pos {
        int r;
        int c;
};

export class Board {
        //Max_row and Column
        int R;
        int C;
        vector<vector<shared_ptr<Link>>> grid;
        vector<vector<int>> firewalls;
public:
        Board();
        int getR() const;
        int getC() const;
        bool inBounds(const Pos &p) const;

        shared_ptr<Link> get(const Pos &p) const;

        void place(const std::shared_ptr<Link>& L, const Pos &p);

        void clearPos(const Pos &p);

        void setFirewall(const Pos &p, char ch);

        char firewallAt(const Pos &p) const;

        void removeFirewall(const Pos &p);

        bool isServer(const Pos &p, int playerID) const;

        bool findLinkPos(const std::shared_ptr<Link>& L, Pos &out) const;

        bool findLinkPosRaw(const Link* raw, Pos &out) const;

};
