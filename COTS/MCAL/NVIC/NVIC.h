#ifndef NVIC_H
#define NVIC_H
#include "Stdtypes.h"

typedef enum{
	
	NVIC_Ok=0,
	NVIC_NotOk, 
	NVIC_WrongConfig,
	NVIC_Invalid_prepheral,
	NVIC_Invalid_priorityLevel,

	
}NVIC_Return;


typedef enum{
	
	Interruprt_Disabled = 0,
	Interruprt_Enabled,
	
}NVIC_Interrupt_Status;



typedef enum{
	
	Interruprt_NotPending = 0,
	Interruprt_Pending,
	
}NVIC_IntrptPend_Status;



typedef enum{
	
	Interruprt_NotActive = 0,
	Interruprt_Active,
	
}NVIC_IntrptActive_Status;



typedef enum{
	
	PriorityLevels_16_Subgroup_0 = 0b000,
	PriorityLevels_8_Subgroup_2 = 0b100,
	PriorityLevels_4_Subgroup_4 = 0b101,
	PriorityLevels_2_Subgroup_8 = 0b110,
	PriorityLevels_0_Subgroup_16 = 0b111,
	
}NVIC_Priority_Mood;



/*

typedef enum {
	
	peripheral_0,
	peripheral_1,
	peripheral_2,
	peripheral_3,
	peripheral_4,
	peripheral_5,
	peripheral_6,
	peripheral_7,
	peripheral_8,
	peripheral_9,
	peripheral_10,
	peripheral_11,
	peripheral_12,
	peripheral_13,
	peripheral_14,
	peripheral_15,
	peripheral_16,
	peripheral_17,
	peripheral_18,
	peripheral_19,
	peripheral_20,
	peripheral_21,
	peripheral_22,
	peripheral_23,
	peripheral_24,
	peripheral_25,
	peripheral_26,
	peripheral_27,
	peripheral_28,
	peripheral_29,
	peripheral_30,
	peripheral_31,
	peripheral_32,
	peripheral_33,
	peripheral_34,
	peripheral_35,
	peripheral_36,
	peripheral_37,
	peripheral_38,
	peripheral_39,
	peripheral_40,
	peripheral_41,
	peripheral_42,
	peripheral_43,
	peripheral_44,
	peripheral_45,
	peripheral_46,
	peripheral_47,
	peripheral_48,
	peripheral_49,
	peripheral_50,
	peripheral_51,
	peripheral_52,
	peripheral_53,
	peripheral_54,
	peripheral_55,
	peripheral_56,
	peripheral_57,
	peripheral_58,
	peripheral_59,
	peripheral_60,
	peripheral_61,
	peripheral_62,
	peripheral_63,
	peripheral_64,
	peripheral_65,
	peripheral_66,
	peripheral_67,
	peripheral_68,
	peripheral_69,
	peripheral_70,
	peripheral_71,
	peripheral_72,
	peripheral_73,
	peripheral_74,
	peripheral_75,
	peripheral_76,
	peripheral_77,
	peripheral_78,
	peripheral_79,
	peripheral_80,
	peripheral_81,
	peripheral_82,
	peripheral_83,
	peripheral_84,
	peripheral_85,
	peripheral_86,
	peripheral_87,
	peripheral_88,
	peripheral_89,
	peripheral_90,
	peripheral_91,
	peripheral_92,
	peripheral_93,
	peripheral_94,
	peripheral_95,
	peripheral_96,
	peripheral_97,
	peripheral_98,
	peripheral_99,
	peripheral_100,
	peripheral_101,
	peripheral_102,
	peripheral_103,
	peripheral_104,
	peripheral_105,
	peripheral_106,
	peripheral_107,
	peripheral_108,
	peripheral_109,
	peripheral_110,
	peripheral_111,
	peripheral_112,
	peripheral_113,
	peripheral_114,
	peripheral_115,
	peripheral_116,
	peripheral_117,
	peripheral_118,
	peripheral_119,
	peripheral_120,
	peripheral_121,
	peripheral_122,
	peripheral_123,
	peripheral_124,
	peripheral_125,
	peripheral_126,
	peripheral_127,
	peripheral_128,
	peripheral_129,
	peripheral_130,
	peripheral_131,
	peripheral_132,
	peripheral_133,
	peripheral_134,
	peripheral_135,
	peripheral_136,
	peripheral_137,
	peripheral_138,
	peripheral_139,
	peripheral_140,
	peripheral_141,
	peripheral_142,
	peripheral_143,
	peripheral_144,
	peripheral_145,
	peripheral_146,
	peripheral_147,
	peripheral_148,
	peripheral_149,
	peripheral_150,
	peripheral_151,
	peripheral_152,
	peripheral_153,
	peripheral_154,
	peripheral_155,
	peripheral_156,
	peripheral_157,
	peripheral_158,
	peripheral_159,
	peripheral_160,
	peripheral_161,
	peripheral_162,
	peripheral_163,
	peripheral_164,
	peripheral_165,
	peripheral_166,
	peripheral_167,
	peripheral_168,
	peripheral_169,
	peripheral_170,
	peripheral_171,
	peripheral_172,
	peripheral_173,
	peripheral_174,
	peripheral_175,
	peripheral_176,
	peripheral_177,
	peripheral_178,
	peripheral_179,
	peripheral_180,
	peripheral_181,
	peripheral_182,
	peripheral_183,
	peripheral_184,
	peripheral_185,
	peripheral_186,
	peripheral_187,
	peripheral_188,
	peripheral_189,
	peripheral_190,
	peripheral_191,
	peripheral_192,
	peripheral_193,
	peripheral_194,
	peripheral_195,
	peripheral_196,
	peripheral_197,
	peripheral_198,
	peripheral_199,
	peripheral_200,
	peripheral_201,
	peripheral_202,
	peripheral_203,
	peripheral_204,
	peripheral_205,
	peripheral_206,
	peripheral_207,
	peripheral_208,
	peripheral_209,
	peripheral_210,
	peripheral_211,
	peripheral_212,
	peripheral_213,
	peripheral_214,
	peripheral_215,
	peripheral_216,
	peripheral_217,
	peripheral_218,
	peripheral_219,
	peripheral_220,
	peripheral_221,
	peripheral_222,
	peripheral_223,
	peripheral_224,
	peripheral_225,
	peripheral_226,
	peripheral_227,
	peripheral_228,
	peripheral_229,
	peripheral_230,
	peripheral_231,
	peripheral_232,
	peripheral_233,
	peripheral_234,
	peripheral_235,
	peripheral_236,
	peripheral_237,
	peripheral_238,
	peripheral_239,

}Peripherals;
*/



/*enter the peripheral num. from 0 to 239 */
NVIC_Return Enable_Interrupt(u8 cpy_peripheral_num); 


/*enter the peripheral num. from 0 to 239 */
NVIC_Return Disable_Interrupt(u8 cpy_peripheral_num);


/*enter the peripheral num. from 0 to 239 */
NVIC_Return Get_Interrupt_Status(u8 cpy_peripheral_num ,u8* Status);


/*enter the peripheral num. from 0 to 239 */
NVIC_Return Set_Pending(u8 cpy_peripheral_num);


/*enter the peripheral num. from 0 to 239 */
NVIC_Return Clear_Pending(u8 cpy_peripheral_num);


/*enter the peripheral num. from 0 to 239 */
NVIC_Return Get_Intrpt_Pend_Status(u8 cpy_peripheral_num ,u8* Status);


/*enter the peripheral num. from 0 to 239 */
NVIC_Return Get_Intrpt_Active_Status(u8 cpy_peripheral_num ,u8* Status);


NVIC_Return Configure_PriorityMood(NVIC_Priority_Mood);


NVIC_Return Get_PriorityMood(NVIC_Priority_Mood* PriorityMood);


/*enter the peripheral num. from 0 to 239  ||||  enter the priorityLeve and subgroup_level according to the priority mood you choose  */
NVIC_Return Set_PriorityLevel(u8 cpy_peripheral_num , u8 priority_level , u8 subgroup_level);



#endif /* NVIC_H */
