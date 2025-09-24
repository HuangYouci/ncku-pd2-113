## Subtask 2
> 請簡單解釋此 do-while 迴圈如何運作。
這裡將持續檢查 judge.mainPage() 的回傳值

如果回傳非 0，就結束這個程式
可能是在 Judge 主畫面控制要不要退出程式的功能

## Subtask 3
> 為什麼可以使用 JudgeSystem 的 mainPage?

因為已經在上面建立一個 JudgeSystem class 的實例 judge
因此可使用 judge 的 public 函式 mainPage();

## Subtask 5
> 為什麼 main.cpp 一定要透過 JudgeSystem 的變數才能呼叫 mainPage？

類別（class）是物件導向的基本單位，成員函式（method）是屬於實例（instance）的。因此，如果 mainPage 不是 static 函式，那它就屬於 JudgeSystem 這個類別的某個實例，而非類別本身。

如果想要使用 JudgeSystem::mainPage()，就必須先創建一個 JudgeSystem 的實例，然後透過該實例來呼叫它，例如：

```cpp
JudgeSystem judge;
judge.mainPage();
```

mainPage() 需要訪問 JudgeSystem 內部的非 static 變數，而這些變數是每個物件獨立擁有的，因此必須透過實例來存取它們。

如果 mainPage() 是 static 的，那麼就可以直接使用 JudgeSystem::mainPage(); 而不需要創建物件，因為 static 函式不屬於特定物件，而是屬於整個類型。

## Subtask 6
> 為什麼 JudgeSystem.cpp 可以不透過變數來直接呼叫 AccountSystem 的 login() 函式？

在 JudgeSystem 裡，它可以直接呼叫 login()，因為 JudgeSystem 用 private 繼承了 AccountSystem：

```cpp
class JudgeSystem : private AccountSystem, private ProblemSystem, private MainPage
```
當一個類型繼承另一個類型時，它會獲得父類別的成員。這表示 JudgeSystem 裡面已經包含了 AccountSystem 的功能，不需要另外創建一個 AccountSystem 的物件。

像是自己就是一個 AccountSystem，所以可以直接用 login()，不用透過額外的變數。

## Subtask 7
> protected 權限的影響

### 7-1
> 如果 login() 是 public，JudgeSystem.cpp 可以呼叫嗎？為什麼？

JudgeSystem.cpp 可以直接呼叫 login()。因為 public 函式可被所有程式碼存取。例如提供的 Template 程式碼：

```cpp
std::pair<bool, std::string> user_info = AccountSystem::login();
```

### 7-2
> 如果 login() 是 private，JudgeSystem.cpp 可以呼叫嗎？為什麼？

不行，因 private 成員函式只能被該類別本身存取，無法被其他類別或外部程式碼直接呼叫。

```cpp
std::pair<bool, std::string> user_info = AccountSystem::login(); // 錯誤
```

### 7-3
> protected 屬性的成員有誰可以存取？

protected 介於 private 和 public 之間，可存取的對象：
- 自己
- 繼承該類型的子類型

如：
```cpp
class mama {
protected:
    int x;
};

class baby : public mama {
public:
    void printX() {
        std::cout << x;  // 可以
    }
};

int main() {
    mama mymama;
    std::cout << mymama.x;  // 不行
}
```

## Subtask 11
> 請解釋上方的 try-catch 語法如何運作。

try-catch 是 C++ 處理例外狀況的程式碼。當程式可能發生錯誤時，他可以捕捉這些錯誤，然後好好處理。


- try
    ```cpp
    try {
        // 可能會出錯的程式碼
    }
    ```
    try 是一個關鍵字，後面跟著一個大括號 {}，裡面放的是「可能會發生錯誤」的程式碼。

    程式會從上到下執行 try 裡的每一行。
    如果一切順利（沒出錯），就正常跑完，然後跳過 catch，繼續執行後面的程式碼。

    如果某一行丟出例外（exception），程式會立刻停止 try 裡的執行，跳到 catch 區塊。

- throw
    ```cpp
    if (!info_out) {
        throw std::runtime_error("Error: File does not exist - " + USER_DATA_PATH);
    }
    ```
    throw 是用來丟出例外的關鍵字。指定錯誤區塊進行錯誤處理。
    一旦 throw 被執行，程式不會繼續跑 try 裡後面的程式碼（例如 for 迴圈），而是直接跳到 catch。

- catch
    ```cpp
    catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << "\n";
    }
    ```
    catch 是用來執行當 try 發生錯誤時的程式們。
    如果 try 丟出了錯誤，程式會跳到這個 catch。

    執行完 catch 後，程式繼續往下跑。