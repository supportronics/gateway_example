


#ifndef __PE_Types_H
#define __PE_Types_H

#ifndef FALSE
  #define  FALSE  0
#endif
#ifndef TRUE
  #define  TRUE   1
#endif

typedef unsigned char       VUINT8;
typedef signed char         VINT8;
typedef unsigned short int  VUINT16;
typedef signed short int    VINT16;
typedef unsigned long int   VUINT32;

#ifndef int8_t
typedef signed char int8_t;
#endif
#ifndef int16_t
typedef signed int   int16_t;
#endif
#ifndef int32_t
typedef signed long int    int32_t;
#endif

#ifndef uint8_t
typedef unsigned char       uint8_t;
#endif
#ifndef uint16_t
typedef unsigned int  uint16_t;
#endif
#ifndef uint32_t
typedef unsigned long int   uint32_t;
#endif

typedef unsigned char bool;
typedef unsigned char byte;
typedef unsigned int word;
typedef unsigned long dword;
typedef unsigned long dlong[2];
typedef void (*tIntFunc)(void);
typedef uint8_t TPE_ErrCode;

#define setRegBit(reg, bit)                                     (reg |= reg##_##bit##_##MASK)
#define clrRegBit(reg, bit)                                     (reg &= ~reg##_##bit##_##MASK)
#define getRegBit(reg, bit)                                     (reg & reg##_##bit##_##MASK)
#define setReg(reg, val)                                        (reg = (word)(val))
#define getReg(reg)                                             (reg)
#define setRegBits(reg, mask)                                   (reg |= (word)(mask))
#define getRegBits(reg, mask)                                   (reg & (word)(mask))
#define clrRegBits(reg, mask)                                   (reg &= (word)(~(mask)))
#define setRegBitGroup(reg, bits, val)                          (reg = (word)((reg & ~reg##_##bits##_##MASK) | ((val) << reg##_##bits##_##BITNUM)))
#define getRegBitGroup(reg, bits)                               ((reg & reg##_##bits##_##MASK) >> reg##_##bits##_##BITNUM)
#define setRegMask(reg, maskAnd, maskOr)                        (reg = (word)((getReg(reg) & ~(maskAnd)) | (maskOr)))
#define setRegBitVal(reg, bit, val)                             ((val) == 0 ? (reg &= ~reg##_##bit##_##MASK) : (reg |= reg##_##bit##_##MASK))
#define changeRegBits(reg, mask)                                (reg ^= (mask))
#define changeRegBit(reg, bit)                                  (reg ^= reg##_##bit##_##MASK)

#define setReg16Bit(RegName, BitName)                           (RegName |= RegName##_##BitName##_##MASK)
#define clrReg16Bit(RegName, BitName)                           (RegName &= ~RegName##_##BitName##_##MASK)
#define invertReg16Bit(RegName, BitName)                        (RegName ^= RegName##_##BitName##_##MASK)
#define testReg16Bit(RegName, BitName)                          (RegName & RegName##_##BitName##_##MASK)

#define setReg16(RegName, val)                                  (RegName = (word)(val))
#define getReg16(RegName)                                       (RegName)

#define testReg16Bits(RegName, GetMask)                         (RegName & (GetMask))
#define clrReg16Bits(RegName, ClrMask)                          (RegName &= ~(word)(ClrMask))
#define setReg16Bits(RegName, SetMask)                          (RegName |= (word)(SetMask))
#define invertReg16Bits(RegName, InvMask)                       (RegName ^= (word)(InvMask))
#define clrSetReg16Bits(RegName, ClrMask, SetMask)              (RegName = (RegName & (~(word)(ClrMask))) | (word)(SetMask))
#define seqClrSetReg16Bits(RegName, BitsMask, BitsVal)          (RegName &= ~(~(word)(BitsVal) & (word)(BitsMask)),\
                                                                RegName |= (word)(BitsVal) & (word)(BitsMask) )
#define seqSetClrReg16Bits(RegName, BitsMask, BitsVal)          (RegName |= (word)(BitsVal) & (word)(BitsMask),\
                                                                RegName &= ~(~(word)(BitsVal) & (word)(BitsMask)) )
#define seqResetSetReg16Bits(RegName, BitsMask, BitsVal)        (RegName &= ~(word)(BitsMask),\
                                                                RegName |= (word)(BitsVal) & (word)(BitsMask) )
#define clrReg16BitsByOne(RegName, ClrMask, BitsMask)           (RegName &= (word)(ClrMask) & (word)(BitsMask))

#define testReg16BitGroup(RegName, GroupName)                   (RegName & RegName##_##GroupName##_##MASK)
#define getReg16BitGroupVal(RegName, GroupName)                 ((RegName & RegName##_##GroupName##_##MASK) >> RegName##_##GroupName##_##BITNUM)
#define setReg16BitGroupVal(RegName, GroupName, GroupVal)       (RegName = (RegName & ~RegName##_##GroupName##_##MASK) | ((GroupVal) << RegName##_##GroupName##_##BITNUM))
#define seqClrSetReg16BitGroupVal(RegName,GroupName,GroupVal)   (RegName &= ~(~((GroupVal) << RegName##_##GroupName##_##BITNUM) & RegName##_##GroupName##_##MASK),\
                                                                RegName |= ((GroupVal) << RegName##_##GroupName##_##BITNUM) & RegName##_##GroupName##_##MASK )
#define seqSetClrReg16BitGroupVal(RegName,GroupName,GroupVal)   (RegName |= ((GroupVal) << RegName##_##GroupName##_##BITNUM) & RegName##_##GroupName##_##MASK,\
                                                                RegName &= ~(~((GroupVal) << RegName##_##GroupName##_##BITNUM) & RegName##_##GroupName##_##MASK) )
#define seqResetSetReg16BitGroupVal(RegName,GroupName,GroupVal) (RegName &= ~RegName##_##GroupName##_##MASK,\
                                                                RegName |= ((GroupVal) << RegName##_##GroupName##_##BITNUM) & RegName##_##GroupName##_##MASK )

#define setReg8Bit(RegName, BitName)                             (RegName |= RegName##_##BitName##_##MASK)
#define clrReg8Bit(RegName, BitName)                             (RegName &= ~RegName##_##BitName##_##MASK)
#define invertReg8Bit(RegName, BitName)                          (RegName ^= RegName##_##BitName##_##MASK)
#define testReg8Bit(RegName, BitName)                            (RegName & RegName##_##BitName##_##MASK)

#define setReg8(RegName, val)                                    (RegName = (byte)(val))
#define getReg8(RegName)                                         (RegName)

#define testReg8Bits(RegName, GetMask)                           (RegName & (GetMask))
#define clrReg8Bits(RegName, ClrMask)                            (RegName &= ~(byte)(ClrMask))
#define setReg8Bits(RegName, SetMask)                            (RegName |= (byte)(SetMask))
#define invertReg8Bits(RegName, InvMask)                         (RegName ^= (byte)(InvMask))
#define clrSetReg8Bits(RegName, ClrMask, SetMask)                (RegName = (RegName & (~(byte)(ClrMask))) | (byte)(SetMask))
#define seqClrSetReg8Bits(RegName, BitsMask, BitsVal)            (RegName &= ~(~(byte)(BitsVal) & (byte)(BitsMask)),\
                                                                 RegName |= (byte)(BitsVal) & (byte)(BitsMask) )
#define seqSetClrReg8Bits(RegName, BitsMask, BitsVal)            (RegName |= (byte)(BitsVal) & (byte)(BitsMask),\
                                                                 RegName &= ~(~(byte)(BitsVal) & (byte)(BitsMask)) )
#define seqResetSetReg8Bits(RegName, BitsMask, BitsVal)          (RegName &= ~(byte)(BitsMask),\
                                                                 RegName |= (byte)(BitsVal) & (byte)(BitsMask) )
#define clrReg8BitsByOne(RegName, ClrMask, BitsMask)             (RegName &= (byte)(ClrMask) & (byte)(BitsMask))

#define testReg8BitGroup(RegName, GroupName)                     (RegName & RegName##_##GroupName##_##MASK)
#define getReg8BitGroupVal(RegName, GroupName)                   ((RegName & RegName##_##GroupName##_##MASK) >> RegName##_##GroupName##_##BITNUM)
#define setReg8BitGroupVal(RegName, GroupName, GroupVal)         (RegName = (RegName & ~RegName##_##GroupName##_##MASK) | ((GroupVal) << RegName##_##GroupName##_##BITNUM))
#define seqClrSetReg8BitGroupVal(RegName,GroupName,GroupVal)     (RegName &= ~(~((GroupVal) << RegName##_##GroupName##_##BITNUM) & RegName##_##GroupName##_##MASK),\
                                                                 RegName |= ((GroupVal) << RegName##_##GroupName##_##BITNUM) & RegName##_##GroupName##_##MASK )
#define seqSetClrReg8BitGroupVal(RegName,GroupName,GroupVal)     (RegName |= ((GroupVal) << RegName##_##GroupName##_##BITNUM) & RegName##_##GroupName##_##MASK,\
                                                                 RegName &= ~(~((GroupVal) << RegName##_##GroupName##_##BITNUM) & RegName##_##GroupName##_##MASK) )
#define seqResetSetReg8BitGroupVal(RegName,GroupName,GroupVal)   (RegName &= ~RegName##_##GroupName##_##MASK,\
                                                                 RegName |= ((GroupVal) << RegName##_##GroupName##_##BITNUM) & RegName##_##GroupName##_##MASK )


#define in16(var,l,h)  (var = ((word)(l)) | (((word)(h)) << 8))
#define out16(l,h,val) (l = (byte)val, h = (byte)(val >> 8))

#define output(P, V) (P = (V))
#define input(P) (P)

#define __DI()  { asm sei; }      
#define __EI()  { asm cli; }      
#define EnterCritical()     { __asm pshc; __asm sei; __asm movb 1,SP+,CCR_reg; } 
#define ExitCritical()  { __asm movb CCR_reg, 1,-SP; __asm pulc; } 
#define SaveStatusReg()     EnterCritical()
#define RestoreStatusReg()  ExitCritical()
#define ISR(x) __interrupt void x(void)


typedef struct {          
  word width;             
  word height;            
  byte *pixmap;           
  word size;              
  int8_t *name;           
} TIMAGE;
typedef TIMAGE* PIMAGE ; 

typedef union {
   word w;
   struct {
     byte high,low;
   } b;
} TWREG;


#endif 


