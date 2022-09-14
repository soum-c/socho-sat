#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'
void fast() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
}

namespace socho_sat {

    struct CNF {

        int var_count;
        vector<vector<int>> clauses;

        CNF() {
            var_count = 0;
        }

        int get_var() {
            var_count++;
            return var_count;
        }

        void set_var_count(int x) {
            var_count = x;
        }

        void add_clause(vector<int> clause) {
            clauses.push_back(clause);
        }

        bool validate() {
            for (auto clause: clauses) {
                for (auto x: clause) {
                    if (x < -var_count || x > var_count) return false; // out of range
                    if (x == 0) return false; // restricted
                }
            }
            return true;
        }

        void output_cnf(bool validate_formula=true) {
            if (validate_formula) {
                if (!validate()) {
                    cerr << "Formula contains an error." << endl;
                    return;
                }
            }
            cout << "p cnf << " << var_count << ' ' << clauses.size() << endl;
            for (auto clause: clauses) {
                for (auto x: clause) {
                    cout << x << ' ';
                }
                cout << 0 << endl;
            }
        }

    };

    CNF unsat() {
        CNF x;
        x.get_var();
        x.add_clause({});
        return x;
    }


};

using namespace socho_sat;

signed main() {
	
	fast(); // for fast IO with cin/cout (useful when output is massive)
	
	
	
}
