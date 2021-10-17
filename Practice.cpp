while (test--) {

        int n, input[200005], output[200005], index = 0;
        vector<pair<int, int>> temp_output;

        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> input[i];
            temp_output.push_back({input[i], i});
        }

        sort(temp_output.begin(), temp_output.end());

        for (int i = 0; i < temp_output.size(); i++) {
            if (index < temp_output[i].first) {
                output[temp_output[i].second] = index;
                index++;
            } else
                output[temp_output[i].second] = temp_output[i].first;
        }

        for (int i = 0; i < n; i++) {
            cout << output[i] << " ";
        }
        cout << endl;
    }
