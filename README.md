# National Cheng Kung University, Program Design II, 2025 Spring, Homework
# 國立成功大學 113-2 程式設計（二） 作業

## 專案簡介
這個 Repository 包含了我在國立成功大學 (NCKU) 113 學年度下學期「程式設計(二)」課程中所完成的作業、期中考與期末考程式碼。所有程式碼皆使用 C++ 撰寫。這個 Repo 的目的是記錄和展示學習過程中的程式碼實作，涵蓋了從物件導向基礎到更複雜的軟體設計與演算法主題。

## 課程
*   **學校**: 國立成功大學 (National Cheng Kung University)
*   **課程名稱**: 程式設計(二)
*   **學期**: 113 學年度 第 2 學期
*   **主要語言**: C++

## 結構
本 Repo 主要包含以下幾個部分的資料夾：

*   **HW2/, HW3/, HW4/, HW5/**: 包含第 2 次到第 5 次作業的程式碼。
    *   每個作業資料夾內包含該次作業的解法。
    *   從 HW3 開始，專案被模組化成 `src/` 資料夾與多個 `.cpp` 檔案。
*   **MIDTERM/**: 包含期中考試的程式碼題目解法 (pA.cpp 至 pF.cpp)。
*   **FINAL/**: 包含期末考試的程式碼題目解法 (pA.cpp 至 pH.cpp)。

## 各部分內容概要
以下簡述各個作業和考試涵蓋的主要概念與技巧：

### **HW2 (`HW2/`)**
*   **主題**: C++ 基礎與資料結構入門。
*   **內容**: 實作一個簡易的商店使用者與購物紀錄管理系統。
*   **涵蓋概念**:
    *   `struct` 的使用 (商品、紀錄、使用者)。
    *   標準模板庫 (STL) 的基本應用，特別是 `std::vector` 與 `std::string`。
    *   基於命令 (如 `register`, `buy`, `summary`) 的輸入處理。
    *   資料的儲存與走訪。

### **HW3 (`HW3/`)**
*   **主題**: 物件導向程式設計 (OOP) 基礎。
*   **內容**: 一個簡易線上評測系統 (Online Judge) 的雛形。
*   **涵蓋概念**:
    *   類別 (Class) 的基本設計 (`AccountSystem`, `JudgeSystem`, `User`, `Problem`)。
    *   檔案 I/O (`fstream`)，用於讀取 `user.csv` 等設定檔。
    *   字串流 (`stringstream`)，用於解析 CSV 格式的資料。
    *   模組化程式設計，將不同功能的類別分割到不同的 `.cpp` 檔案中。
    *   `try-catch` 異常處理。

### **HW4 (`HW4/`)**
*   **主題**: 繼承與多型。
*   **內容**: 模擬一個複雜的家族關係系統，分為「榮國府」和「寧國府」。
*   **涵蓋概念**:
    *   類別繼承：使用 `UserManager` 作為基礎，並衍伸出特定功能的 `RongGuoMansion` 與 `NingGuoMansion`。
    *   樹狀資料結構的模擬 (透過儲存父節點來表示)。
    *   演算法實作：
        *   最近共同祖先 (Lowest Common Ancestor, LCA)。
        *   子集合加總問題 (Subset Sum Problem) 的變形。
    *   函式重載 (`printMagicNumber` 有兩種版本)。

### **HW5 (`HW5/`)**
*   **主題**: 完整應用程式設計與系統互動。
*   **內容**: 將 HW3 的線上評測系統 (Online Judge) 擴充並完成。
*   **涵蓋概念**:
    *   系統呼叫 (`system()`) 的應用，用以執行外部指令 (如呼叫 `g++` 編譯器)。
    *   I/O 重新導向 (`<` 和 `>`)，將測試資料導入使用者程式，並將其輸出寫入檔案。
    *   自動化評測邏輯：編譯、執行、比對使用者輸出與標準答案。
    *   建構一個功能較為完整的 C++ 應用程式。

### **期中考 (`MIDTERM/`)**
*   **主題**: 基礎演算法與問題解決能力。
*   **內容**:
    *   `pA`: 迴圈與條件判斷。
    *   `pB`: 連續子陣列計數。
    *   `pC`: 字串處理 (迴文判斷)。
    *   `pD`: 使用陣列作為頻率表，計算三數之和的唯一組合數。
    *   `pE`: 暴力法/窮舉法，測試所有排列組合以找到最佳解。
    *   `pF`: 簡單的運算式求值。

### **期末考 (`FINAL/`)**
*   **主題**: OOP 進階、複雜演算法與字串處理。
*   **內容**:
    *   **OOP 概念 (pA, pB, pC)**:
        *   `pA`: 基本類別與建構子。
        *   `pB`: 類別繼承。
        *   `pC`: 多型 (Polymorphism)，使用抽象基底類別 (`Reservation`)、虛擬函式 (`virtual getDetails`) 與 `std::sort` 的自訂比較器。
    *   **演算法與資料結構 (pD, pE, pF)**:
        *   `pD`: 數學運算 (餘弦相似度)。
        *   `pE`: 二維陣列應用。
        *   `pF`: `std::sort` 搭配自訂比較函式，對字串進行特殊規則排序。
    *   **進階解析與運算 (pG, pH)**:
        *   `pG`: 使用 `stringstream` 解析帶分數，並實作分數的四則運算。
        *   `pH`: 複雜的遞迴解析器，用於處理巢狀函式呼叫 `f(g(..), h(..))`，並涉及大數運算 (Big Integer) 的概念。

## 主要涵蓋的程式概念
這個 Repository 的程式碼涵蓋了 C++ 的許多核心概念：

*   **C++ 核心**:
    *   基本語法、控制流程、`std::iostream`。
    *   類別 (Class)、物件 (Object)、建構子 (Constructor)。
    *   `std::string`, `std::vector` 等常用 STL 容器。
*   **物件導向 (OOP)**:
    *   封裝 (Encapsulation)。
    *   繼承 (Inheritance)，包含多重繼承。
    *   多型 (Polymorphism)，包含函式重載 (Overloading) 與虛擬函式 (Virtual Functions)。
    *   抽象類別 (Abstract Class)。
*   **資料結構**:
    *   `struct` 與 `class`。
    *   `std::vector`。
    *   樹狀結構的實作與應用 (LCA)。
*   **演算法**:
    *   排序 (`std::sort`) 與自訂比較器。
    *   最近共同祖先 (LCA)。
    *   子集合加總。
    *   遞迴解析 (Recursive Parsing)。
*   **軟體工程**:
    *   模組化程式設計 (使用 `.h` 與 `.cpp` 檔案)。
    *   檔案 I/O (`fstream`) 與字串流 (`stringstream`)。
    *   異常處理 (`try-catch`)。
    *   系統互動 (`system()` 呼叫)。
*   **進階主題**:
    *   大數運算 (Big Integer) 概念。

## 如何編譯與執行
大部分的單一 `.cpp` 檔案可以直接使用 G++ 編譯：

```bash
g++ MIDTERM/pA.cpp -o pA
./pA
```

對於包含多個檔案的專案 (如 HW3, HW4, HW5)，需要將所有相關的 `.cpp` 檔案一起編譯：

```bash 
# 範例：編譯 HW5 的 JudgeSystem
g++ HW5/src/*.cpp -o judge_system
./judge_system
```

對於需要輸入檔的程式，請確保輸入檔與執行檔在同一目錄下，或在執行時提供正確的路徑。

## 注意事項
*   本 Repo 中的程式碼主要用於學習和記錄目的。
*   程式碼風格和效率可能因當時學習階段而異。
*   本 Repo 於該學年度課程結束後才公開。
