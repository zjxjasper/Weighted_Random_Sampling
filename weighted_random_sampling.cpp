#include<vector>
#include<iostream>

using namespace std;
class WRS {
public:
	vector<double> weight;
	vector<double> accu_weight;
	

	void init() {
		int n = weight.size();
		count = vector<int>(n, 0);
		if (n == 0) {
			cout << "weight function size can't be 0\n";
		}
		else {
			accu_weight = weight;
			double tot = 0.0;
			for (int i = 0; i < n; i++) {
				tot += weight[i];
				accu_weight[i] = tot;
			}
			if (tot != 1.0) {
				cout << "total weight is: " << tot << ", rescaling weight\n";
			}
			else {
				for (int i = 0; i < n; i++) {
					accu_weight[i] /= tot;
				}
			}
		}
	}

	int generate_num() {
		double ran = rand()/double(RAND_MAX);
		int st = 0, nd = weight.size() - 1, mid;
		while (nd > st) {
			mid = st + (nd - st) / 2;
			if (ran > accu_weight[mid]) { st = mid + 1; }
			else { nd = mid; }
		}
		return st;
	}

	int weighted_generate() {
		int n = weight.size();
		bool accept = false;
		int ran_int;
		double histo_prob;
		while (accept == false) {
			ran_int = generate_num();
			if (tot_count == 0) accept = true;
			else {
				histo_prob = count[ran_int] / double(tot_count);
				accept = (histo_prob <= weight[ran_int]);
			}
		}
		count[ran_int] ++;
		tot_count ++;
		double histo;
		for (int i = 0; i < n; i++) {
			histo = double(count[i]) / double(tot_count);
			cout << count[i] << " ";
		}
		cout << endl;
		return ran_int;
	}

private:
	vector<int> count;
	int tot_count = 0;
};