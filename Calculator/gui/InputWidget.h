#pragma once

#ifndef INPUT_WIDGET_H
#define INPUT_WIDGET_H

#include"CommandButton.h"
#include<Windows.h>
#include <string>
#include <memory>
#include<map>

#define BTN_WIDTH 60
#define BTN_HEIGH 30

using std::map;
using std::string;

namespace view {

    enum WindowID
    {
        BTN_0,
        BTN_1,
        BTN_2,
        BTN_3,
        BTN_4,
        BTN_5,
        BTN_6,
        BTN_7,
        BTN_8,
        BTN_9,
        BTN_COMMA,
        BTN_PLUS_MINUS,
        BTN_PLUS,
        BTN_MINUS,
        BTN_MULTI,
        BTN_DIVIDE,
        BTN_SHIFT,
        BTN_BKSP,
        BTN_EEX,
        BTN_ENTER,
        BTN_POW,
        BTN_TAN,
        BTN_COS,
        BTN_SIN,
        BTN_UNDO,
        BTN_REDO,
        BTN_PROC,
        LABEL_ASIN,
        LABEL_ACOS,
        LABEL_ATAN,
        LABEL_ROOT,
        LABEL_CLEAR,
        LABEL_SWAP,
    };

    class InputWidget
    {
    public:
        static const string characterEntered;
        static const string enterPressed;
        static const string backspacePressed;
        static const string commandEntered;
        static const string shiftPressed;
        static const string procedurePressed;
    public:

        explicit InputWidget() :m_hwnd{ NULL } {}
        ~InputWidget() = default;

        static LRESULT CALLBACK	InputWindowProc(HWND, UINT, WPARAM, LPARAM);
        HRESULT Create(HWND hParent, int nID, const Rect& rcBound);

        HWND getWindow()const { return m_hwnd; }

        //signals:
        //    void characterEntered(char c);
        //    void enterPressed();
        //    void backspacePressed();
        //    void plusMinusPressed();
        //    void commandEntered(std::string, std::string);
        //    void shiftPressed();
        //    void procedurePressed();

    private:
        void allocateButtons();
        void setupShortcuts();
        void makeConnections();
        void layoutButtons();


    private:
        void onEex();
        void onDecimal();
        void onPlusMinus();
        void onZero();
        void onOne();
        void onTwo();
        void onThree();
        void onFour();
        void onFive();
        void onSix();
        void onSeven();
        void onEight();
        void onNine();

    private:
        HWND m_hwnd;

        static map<size_t, HWND>iGid;
    };

}

#endif

