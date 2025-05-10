#ifndef ADRESS_DEF
#define ADRESS_DEF

/*
 * システム定数定義
 */
#define MAXTBL      64    // テーブルの最大サイズ
#define MAXADRESS   256   // アドレスの最大長
#define MAXNAME     64    // 名前の最大長
#define SCHAR       64    // 文字列の基本サイズ

/*
 * データ型定義
 */
typedef enum item_type {
    TYPE_STRING = 0,      // 文字列型
    TYPE_INT             // 整数型
} item_type;

#endif // ADRESS_DEF
