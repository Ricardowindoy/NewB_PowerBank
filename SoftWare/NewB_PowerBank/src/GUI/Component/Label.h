#ifndef LABEL_H
#define LABEL_H

enum FontStyle
{
    Normal_8,
    Normal_10,
    Normal_12,
    Normal_14,
    Normal_16,
    Normal_18,
};

enum class TextAlign
{   
    // 水平对齐方式 后四位
    Left_H = 0x1,
    Center_H = 0x2,
    Right_H = 0x3,
    // 垂直对齐方式 前四位
    Top_V = 0x1 < 4,
    Center_V = 0x2 < 4,
    Bottom_V =  0x3 < 4,
};
// -1表示自动计算
struct Rect
{
    int32 x;
    int32 y;
    int32 width;
    int32 height;
};

struct Colors
{
    int32 fontColor;
    int32 backColor;
    int32 borderColor;
};

// todo: 添加hover和press消息通知或者回调函数
// 文本标签
class Label
{
    Label();
    ~Label();
public:
    
    SetText(std::string* pText){m_pText = pText;};
    SetRect(Rect stRect){m_stRect = stRect;};
    SetColor(Colors stColor){m_stColor = stColor;};
    SetColorHover(Colors stColor){m_stColorHover = stColor;};
    SetColorPress(Colors stColor){m_stColorPress = stColor;};
    SetStyle(FontStyle enStyle){m_enStyle = enStyle;};
    SetAlign(TextAlign enAlign){m_enAlign = enAlign;};
    SetBlood(bool bBlood){m_bBlood = bBlood;};
    SetRadius(int32 nRadius){m_nRadius = nRadius;};

    GetText(){return m_pText;};
    GetRect(){return m_stRect;};
    GetColor(){return m_stColor;};

protected:
    virtual void Draw();
    virtual void Event();
    virtual void Update();
protected:
    
    Colors m_stColor = {
        0x000000,
        0xFFFFFF,
        0xFFFFFF,
    };
    Colors m_stColorHover = {
        0x000000,
        0xFFFFFF,
        0xFFFFFF,
    };
    Colors m_stColorPress = {
        0x000000,
        0xFFFFFF,
        0xFFFFFF,
    };

    FontStyle m_enStyle = FontStyle::Normal_8;
    
    TextAlign m_enAlign = TextAlign::Left_H | TextAlign::Top_V;

    bool m_bBlood = false;

    std::string* m_pText = nullptr;

    Rect m_stRect = {0, 0, 0, 0};

    int32 m_nRadius = 0;
};

#endif