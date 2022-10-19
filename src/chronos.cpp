#include "chronos.hpp"

using namespace std;

void chronos(int size)
{
    Tree *raiz = CreateTree();
    Tree *aux = CreateTree();
    Record r;

    ifstream dataFile("src/data.txt");
    if (!dataFile.good())
    {
        cout << "Cannot open data!" << endl;
        return;
    }

    float f, g;

    auto start = chrono::high_resolution_clock::now();

    int i = 0;

    while (dataFile >> f && i < size)
    {
        r.key = f;
        r.value = 1;
        insertTree(&raiz, r);
        i++;
    }

    auto end = chrono::high_resolution_clock::now();

    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    cout << "Tempo de montagem na memória (" << size << "): " << fixed << time_taken << setprecision(9) << " sec" << endl;
    cout << endl;
    dataFile.clear();
    dataFile.seekg(0, ios::beg);

    ifstream inputFile("src/input.txt");
    if (!dataFile.good())
    {
        cout << "Cannot open input!" << endl;
        return;
    }

    start = chrono::high_resolution_clock::now();

    while (inputFile >> g)
    {
        r.key = g;
        pesquisa(&raiz, &aux, r);
    }

    end = chrono::high_resolution_clock::now();

    time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    cout << "Tempo de pesquisa: " << fixed << time_taken << setprecision(9) << " sec" << endl;
    cout << endl;
    inputFile.clear();
    inputFile.seekg(0, ios::beg);

    start = chrono::high_resolution_clock::now();

    while (inputFile >> g)
    {
        r.key = g;
        removeTree(&raiz, r);
    }

    end = chrono::high_resolution_clock::now();

    time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    cout << "Tempo de remoção: " << fixed << time_taken << setprecision(9) << " sec" << endl;
    cout << endl;
    inputFile.close();
    dataFile.close();
}

void chronosAVL(int size)

{
    TreeAVL *raizAVL = CreateTreeAVL();
    TreeAVL *auxAVL = CreateTreeAVL();
    RecordAVL rAVL;

    ifstream dataFile("src/data.txt");
    if (!dataFile.good())
    {
        cout << "Cannot open data!" << endl;
        return;
    }

    float f, g;

    auto start = chrono::high_resolution_clock::now();

    int i = 0;

    while (dataFile >> f && i < size)
    {
        rAVL.key = f;
        rAVL.value = 1;
        insertTreeAVL(&raizAVL, rAVL);
        i++;
    }

    auto end = chrono::high_resolution_clock::now();

    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    cout << "Tempo de montagem na memória (" << size << "): " << fixed << time_taken << setprecision(9) << " sec" << endl;
    cout << endl;
    dataFile.clear();
    dataFile.seekg(0, ios::beg);

    ifstream inputFile("src/input.txt");
    if (!dataFile.good())
    {
        cout << "Cannot open input!" << endl;
        return;
    }

    start = chrono::high_resolution_clock::now();

    while (inputFile >> g)
    {
        rAVL.key = g;
        pesquisaAVL(&raizAVL, &auxAVL, rAVL);
    }

    end = chrono::high_resolution_clock::now();

    time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    cout << "Tempo de pesquisa: " << fixed << time_taken << setprecision(9) << " sec" << endl;
    cout << endl;
    inputFile.clear();
    inputFile.seekg(0, ios::beg);

    start = chrono::high_resolution_clock::now();

    while (inputFile >> g)
    {
        rAVL.key = g;
        removeTreeAVL(&raizAVL, &auxAVL, rAVL);
    }

    end = chrono::high_resolution_clock::now();

    time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    cout << "Tempo de remoção: " << fixed << time_taken << setprecision(9) << " sec" << endl;
    cout << endl;
    inputFile.close();
    dataFile.close();
}

void chronosRBT(int size)
{
    TreeRBT *raizRBT = CreateTreeRBT();
    RecordRBT rRBT;

    ifstream dataFile("src/data.txt");
    if (!dataFile.good())
    {
        cout << "Cannot open data!" << endl;
        return;
    }

    float f, g;

    auto start = chrono::high_resolution_clock::now();

    int i = 0;

    while (dataFile >> f && i < size)
    {
        rRBT.key = f;
        rRBT.value = 1;
        insertTreeRBT(&raizRBT, &raizRBT, &raizRBT, rRBT);
        i++;
    }

    auto end = chrono::high_resolution_clock::now();

    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    cout << "Tempo de montagem na memória (" << size << "): " << fixed << time_taken << setprecision(9) << " sec" << endl;
    cout << endl;
    dataFile.clear();
    dataFile.seekg(0, ios::beg);

    ifstream inputFile("src/input.txt");
    if (!dataFile.good())
    {
        cout << "Cannot open input!" << endl;
        return;
    }

    start = chrono::high_resolution_clock::now();

    while (inputFile >> g)
    {
        rRBT.key = g;
        pesquisaRBT(&raizRBT, &raizRBT, rRBT);
    }

    end = chrono::high_resolution_clock::now();

    time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    cout << "Tempo de pesquisa: " << fixed << time_taken << setprecision(9) << " sec" << endl;
    cout << endl;
    inputFile.clear();
    inputFile.seekg(0, ios::beg);

    // start = chrono::high_resolution_clock::now();

    // while (inputFile >> g)
    // {
    //     rRBT.key = g;
    //     removeTreeRBT(&raizRBT, &auxRBT, rRBT);
    // }

    // end = chrono::high_resolution_clock::now();

    // time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    // time_taken *= 1e-9;
    // cout << "Tempo de remoção: " << fixed << time_taken << setprecision(9) << " sec" << endl;
    // cout << endl;
    inputFile.close();
    dataFile.close();
}

void chronosVector(int size)
{
    vector<float> v;

    ifstream dataFile("src/data.txt");
    if (!dataFile.good())
    {
        cout << "Cannot open data!" << endl;
        return;
    }
    float f, g;
    int i = 0;

    auto start = chrono::high_resolution_clock::now();
    while (dataFile >> f && i < size)
    {
        v.push_back(f);
        i++;
    }
    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    cout << "Tempo de montagem na memória (" << size << "): " << fixed << time_taken << setprecision(9) << " sec" << endl;
    cout << endl;
    dataFile.clear();
    dataFile.seekg(0, ios::beg);

    start = chrono::high_resolution_clock::now();
    sort(v.begin(), v.end());
    end = chrono::high_resolution_clock::now();
    time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    cout << "Tempo de ordenação do vetor: " << fixed << time_taken << setprecision(9) << " sec" << endl;
    cout << endl;

    ifstream inputFile("src/input.txt");
    if (!dataFile.good())
    {
        cout << "Cannot open input!" << endl;
        return;
    }

    start = chrono::high_resolution_clock::now();

    while (inputFile >> g)
    {
        binary_search(v.begin(), v.end(), g);
    }

    end = chrono::high_resolution_clock::now();

    time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    cout << "Tempo de pesquisa: " << fixed << time_taken << setprecision(9) << " sec" << endl;
    cout << endl;
    inputFile.clear();
    inputFile.seekg(0, ios::beg);

    start = chrono::high_resolution_clock::now();
    while (inputFile >> g)
    {
        auto it = lower_bound(v.begin(), v.end(), g);
        if (it != v.end() && *it == g)
            v.erase(it);
    }

    end = chrono::high_resolution_clock::now();

    time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    cout << "Tempo de remoção: " << fixed << time_taken << setprecision(9) << " sec" << endl;
    cout << endl;
    inputFile.close();
    dataFile.close();
}

void chronosMap(int size)
{
    map<float, int> data;

    ifstream dataFile("src/data.txt");
    if (!dataFile.good())
    {
        cout << "Cannot open data!" << endl;
        return;
    }
    float f, g;
    int i = 0;

    auto start = chrono::high_resolution_clock::now();
    while (dataFile >> f && i < size)
    {
        data.insert(make_pair(f, i));
        i++;
    }
    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    cout << "Tempo de montagem na memória (" << size << "): " << fixed << time_taken << setprecision(9) << " sec" << endl;
    cout << endl;
    dataFile.clear();
    dataFile.seekg(0, ios::beg);

    ifstream inputFile("src/input.txt");
    if (!dataFile.good())
    {
        cout << "Cannot open input!" << endl;
        return;
    }

    start = chrono::high_resolution_clock::now();
    while (inputFile >> g)
    {
        data.find(g);
    }

    end = chrono::high_resolution_clock::now();

    time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    cout << "Tempo de pesquisa: " << fixed << time_taken << setprecision(9) << " sec" << endl;
    cout << endl;
    inputFile.clear();
    inputFile.seekg(0, ios::beg);
    start = chrono::high_resolution_clock::now();
    while (inputFile >> g)
    {
        data.erase(g);
    }

    end = chrono::high_resolution_clock::now();

    time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    cout << "Tempo de remoção: " << fixed << time_taken << setprecision(9) << " sec" << endl;
    cout << endl;
    inputFile.close();
    dataFile.close();
}

void chronosUnorderedMap(int size)
{
    unordered_map<float, int> data;

    ifstream dataFile("src/data.txt");
    if (!dataFile.good())
    {
        cout << "Cannot open data!" << endl;
        return;
    }
    float f, g;
    int i = 0;

    auto start = chrono::high_resolution_clock::now();
    while (dataFile >> f && i < size)
    {
        data.insert(make_pair(f, i));
        i++;
    }
    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    cout << "Tempo de montagem na memória (" << size << "): " << fixed << time_taken << setprecision(9) << " sec" << endl;
    cout << endl;
    dataFile.clear();
    dataFile.seekg(0, ios::beg);

    ifstream inputFile("src/input.txt");
    if (!dataFile.good())
    {
        cout << "Cannot open input!" << endl;
        return;
    }

    start = chrono::high_resolution_clock::now();
    while (inputFile >> g)
    {
        data.find(g);
    }

    end = chrono::high_resolution_clock::now();

    time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    cout << "Tempo de pesquisa: " << fixed << time_taken << setprecision(9) << " sec" << endl;
    cout << endl;
    inputFile.clear();
    inputFile.seekg(0, ios::beg);
    start = chrono::high_resolution_clock::now();
    while (inputFile >> g)
    {
        data.erase(g);
    }

    end = chrono::high_resolution_clock::now();

    time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    cout << "Tempo de remoção: " << fixed << time_taken << setprecision(9) << " sec" << endl;
    cout << endl;
    inputFile.close();
    dataFile.close();
}