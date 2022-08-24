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

#define CHARACTER_ENTERED   600

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
        // message send by this Class
        static UINT uCharacterEnteredMsg;
        static UINT uCommandEnteredMsg;
        static UINT uEnterPressedMsg;
        static UINT uProcedurePressedMsg;
        static UINT uShiftPressedMsg;
        static UINT uPlusMinusMsg;

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
        static void shiftPressed();
        //    void procedurePressed();

    private:
        void allocateButtons();
        void setupShortcuts();
        void makeConnections();
        void layoutButtons();


    private:
        static void onEex();
        static void onDecimal();
        static void onPlusMinus();
        static void onZero();
        static void onOne();
        static void onTwo();
        static void onThree();
        static void onFour();
        static void onFive();
        static void onSix();
        static void onSeven();
        static void onEight();
        static void onNine();

    private:
        HWND m_hwnd;

        static map<size_t, HWND>iGid;
    };

}

#endif

