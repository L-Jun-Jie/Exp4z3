(set-info :smt-lib-version 2.6)
(set-logic QF_ALIA)
(set-info :source |
Unbounded version of the queue lock algorithm.


|)
(set-info :category "industrial")
(set-info :status sat)
(declare-fun x_0 () (Array Int Int))
(declare-fun x_1 () Int)
(declare-fun x_2 () Int)
(declare-fun x_3 () (Array Int Int))
(declare-fun x_4 () (Array Int Int))
(declare-fun x_5 () (Array Int Int))
(declare-fun x_6 () (Array Int Int))
(declare-fun x_7 () (Array Int Int))
(declare-fun x_8 () (Array Int Int))
(declare-fun x_9 () (Array Int Int))
(declare-fun x_10 () (Array Int Int))
(declare-fun x_11 () (Array Int Int))
(declare-fun x_12 () (Array Int Int))
(declare-fun x_13 () (Array Int Int))
(declare-fun x_14 () (Array Int Int))
(declare-fun x_15 () Int)
(declare-fun x_16 () Int)
(declare-fun x_17 () (Array Int Int))
(declare-fun x_18 () Int)
(declare-fun x_19 () Bool)
(declare-fun x_20 () Bool)
(declare-fun x_21 () Int)
(declare-fun x_22 () Int)
(declare-fun x_23 () Int)
(declare-fun x_24 () Int)
(declare-fun x_25 () Int)
(declare-fun x_26 () Int)
(declare-fun x_27 () Int)
(declare-fun x_28 () Int)
(declare-fun x_29 () Int)
(declare-fun x_30 () Int)
(declare-fun x_31 () Int)
(declare-fun x_32 () Int)
(declare-fun x_33 () (Array Int Int))
(declare-fun x_34 () Int)
(declare-fun x_35 () Bool)
(declare-fun x_36 () Int)
(declare-fun x_37 () Int)
(declare-fun x_38 () Int)
(declare-fun x_39 () Int)
(declare-fun x_40 () Int)
(declare-fun x_41 () Int)
(declare-fun x_42 () Int)
(declare-fun x_43 () Int)
(declare-fun x_44 () Int)
(declare-fun x_45 () Int)
(declare-fun x_46 () (Array Int Int))
(declare-fun x_47 () Int)
(declare-fun x_48 () Bool)
(declare-fun x_49 () Int)
(declare-fun x_50 () Int)
(declare-fun x_51 () Int)
(declare-fun x_52 () Int)
(declare-fun x_53 () Int)
(declare-fun x_54 () Int)
(declare-fun x_55 () Int)
(declare-fun x_56 () Int)
(declare-fun x_57 () Int)
(declare-fun x_58 () Int)
(declare-fun x_59 () (Array Int Int))
(declare-fun x_60 () Int)
(declare-fun x_61 () Bool)
(declare-fun x_62 () Int)
(declare-fun x_63 () Int)
(declare-fun x_64 () Int)
(declare-fun x_65 () Int)
(declare-fun x_66 () Int)
(declare-fun x_67 () Int)
(declare-fun x_68 () Int)
(declare-fun x_69 () Int)
(declare-fun x_70 () Int)
(declare-fun x_71 () Int)
(declare-fun x_72 () (Array Int Int))
(declare-fun x_73 () Int)
(declare-fun x_74 () Bool)
(declare-fun x_75 () Int)
(declare-fun x_76 () Int)
(declare-fun x_77 () Int)
(declare-fun x_78 () Int)
(declare-fun x_79 () Int)
(declare-fun x_80 () Int)
(declare-fun x_81 () Int)
(declare-fun x_82 () Int)
(declare-fun x_83 () Int)
(declare-fun x_84 () Int)
(declare-fun x_85 () (Array Int Int))
(declare-fun x_86 () Int)
(declare-fun x_87 () Bool)
(declare-fun x_88 () Int)
(declare-fun x_89 () Int)
(declare-fun x_90 () Int)
(declare-fun x_91 () Int)
(declare-fun x_92 () Int)
(declare-fun x_93 () Int)
(declare-fun x_94 () Int)
(declare-fun x_95 () Int)
(declare-fun x_96 () Int)
(declare-fun x_97 () Int)
(declare-fun x_98 () (Array Int Int))
(declare-fun x_99 () Int)
(declare-fun x_100 () Bool)
(declare-fun x_101 () Int)
(declare-fun x_102 () Int)
(declare-fun x_103 () Int)
(declare-fun x_104 () Int)
(declare-fun x_105 () Int)
(declare-fun x_106 () Int)
(declare-fun x_107 () Int)
(declare-fun x_108 () Int)
(declare-fun x_109 () Int)
(declare-fun x_110 () Int)
(declare-fun x_111 () (Array Int Int))
(declare-fun x_112 () Int)
(declare-fun x_113 () Bool)
(declare-fun x_114 () Int)
(declare-fun x_115 () Int)
(declare-fun x_116 () Int)
(declare-fun x_117 () Int)
(declare-fun x_118 () Int)
(declare-fun x_119 () Int)
(declare-fun x_120 () Int)
(declare-fun x_121 () Int)
(declare-fun x_122 () Int)
(declare-fun x_123 () Int)
(declare-fun x_124 () (Array Int Int))
(declare-fun x_125 () Int)
(declare-fun x_126 () Bool)
(declare-fun x_127 () Int)
(declare-fun x_128 () Int)
(declare-fun x_129 () Int)
(declare-fun x_130 () Int)
(declare-fun x_131 () Int)
(declare-fun x_132 () Int)
(declare-fun x_133 () Int)
(declare-fun x_134 () Int)
(declare-fun x_135 () Int)
(declare-fun x_136 () Int)
(declare-fun x_137 () (Array Int Int))
(declare-fun x_138 () Int)
(declare-fun x_139 () Bool)
(declare-fun x_140 () Int)
(declare-fun x_141 () Int)
(declare-fun x_142 () Int)
(declare-fun x_143 () Int)
(declare-fun x_144 () Int)
(declare-fun x_145 () Int)
(declare-fun x_146 () Int)
(declare-fun x_147 () Int)
(declare-fun x_148 () Int)
(declare-fun x_149 () Int)
(declare-fun x_150 () (Array Int Int))
(declare-fun x_151 () Int)
(declare-fun x_152 () Bool)
(declare-fun x_153 () Int)
(declare-fun x_154 () Int)
(declare-fun x_155 () Int)
(declare-fun x_156 () Int)
(declare-fun x_157 () Int)
(declare-fun x_158 () Int)
(declare-fun x_159 () Int)
(declare-fun x_160 () Int)
(declare-fun x_161 () Int)
(declare-fun x_162 () Int)
(declare-fun x_163 () (Array Int Int))
(declare-fun x_164 () Int)
(declare-fun x_165 () Bool)
(declare-fun x_166 () Int)
(declare-fun x_167 () Int)
(declare-fun x_168 () Int)
(declare-fun x_169 () Int)
(declare-fun x_170 () Int)
(declare-fun x_171 () (Array Int Int))
(declare-fun x_172 () Int)
(declare-fun x_173 () Int)
(declare-fun x_174 () Int)
(declare-fun x_175 () Int)
(declare-fun x_176 () Int)
(declare-fun x_177 () Int)
(declare-fun x_178 () Int)
(declare-fun x_179 () Int)
(declare-fun x_180 () Int)
(declare-fun x_181 () Int)
(declare-fun x_182 () Int)
(declare-fun x_183 () Int)
(declare-fun x_184 () Int)
(declare-fun x_185 () Int)
(declare-fun x_186 () Int)
(declare-fun x_187 () Int)
(declare-fun x_188 () Int)
(declare-fun x_189 () Int)
(declare-fun x_190 () Int)
(declare-fun x_191 () Int)
(declare-fun x_192 () Int)
(declare-fun x_193 () Int)
(declare-fun x_194 () Int)
(declare-fun x_195 () Int)
(declare-fun x_196 () Int)
(declare-fun x_197 () Int)
(declare-fun x_198 () Int)
(declare-fun x_199 () Int)
(declare-fun x_200 () Int)
(declare-fun x_201 () Int)
(declare-fun x_202 () Int)
(declare-fun x_203 () Int)
(declare-fun x_204 () Int)
(declare-fun x_205 () Int)
(declare-fun x_206 () Int)
(declare-fun x_207 () Int)
(declare-fun x_208 () Int)
(declare-fun x_209 () Int)
(declare-fun x_210 () Int)
(declare-fun x_211 () Int)
(declare-fun x_212 () Int)
(declare-fun x_213 () Int)
(declare-fun x_214 () Int)
(declare-fun x_215 () Int)
(declare-fun x_216 () Int)
(declare-fun x_217 () Int)
(declare-fun x_218 () Int)
(declare-fun x_219 () Int)
(declare-fun x_220 () Int)
(declare-fun x_221 () Int)
(declare-fun x_222 () Int)
(declare-fun x_223 () Int)
(declare-fun x_224 () Int)
(declare-fun x_225 () Int)
(declare-fun x_226 () Int)
(declare-fun x_227 () Int)
(declare-fun x_228 () Int)
(declare-fun x_229 () Int)
(declare-fun x_230 () Int)
(declare-fun x_231 () Int)
(declare-fun x_232 () Int)
(declare-fun x_233 () Int)
(declare-fun x_234 () Int)
(declare-fun x_235 () Int)
(declare-fun x_236 () Int)
(declare-fun x_237 () Int)
(declare-fun x_238 () Int)
(declare-fun x_239 () Int)
(declare-fun x_240 () Int)
(declare-fun x_241 () Int)
(declare-fun x_242 () Int)
(declare-fun x_243 () Int)
(declare-fun x_244 () Int)
(declare-fun x_245 () Int)
(declare-fun x_246 () Int)
(declare-fun x_247 () Int)
(declare-fun x_248 () Int)
(declare-fun x_249 () Int)
(assert (let ((?v_58 (= x_17 x_14)) (?v_55 (= x_18 x_15)) (?v_56 (= x_19 x_20)) (?v_59 (= x_21 x_22)) (?v_57 (not (<= x_22 x_15))) (?v_53 (= x_33 x_17)) (?v_50 (= x_34 x_18)) (?v_51 (= x_35 x_19)) (?v_54 (= x_36 x_21)) (?v_52 (not (<= x_21 x_18))) (?v_48 (= x_46 x_33)) (?v_45 (= x_47 x_34)) (?v_46 (= x_48 x_35)) (?v_49 (= x_49 x_36)) (?v_47 (not (<= x_36 x_34))) (?v_43 (= x_59 x_46)) (?v_40 (= x_60 x_47)) (?v_41 (= x_61 x_48)) (?v_44 (= x_62 x_49)) (?v_42 (not (<= x_49 x_47))) (?v_38 (= x_72 x_59)) (?v_35 (= x_73 x_60)) (?v_36 (= x_74 x_61)) (?v_39 (= x_75 x_62)) (?v_37 (not (<= x_62 x_60))) (?v_33 (= x_85 x_72)) (?v_30 (= x_86 x_73)) (?v_31 (= x_87 x_74)) (?v_34 (= x_88 x_75)) (?v_32 (not (<= x_75 x_73))) (?v_28 (= x_98 x_85)) (?v_25 (= x_99 x_86)) (?v_26 (= x_100 x_87)) (?v_29 (= x_101 x_88)) (?v_27 (not (<= x_88 x_86))) (?v_23 (= x_111 x_98)) (?v_20 (= x_112 x_99)) (?v_21 (= x_113 x_100)) (?v_24 (= x_114 x_101)) (?v_22 (not (<= x_101 x_99))) (?v_18 (= x_124 x_111)) (?v_15 (= x_125 x_112)) (?v_16 (= x_126 x_113)) (?v_19 (= x_127 x_114)) (?v_17 (not (<= x_114 x_112))) (?v_13 (= x_137 x_124)) (?v_10 (= x_138 x_125)) (?v_11 (= x_139 x_126)) (?v_14 (= x_140 x_127)) (?v_12 (not (<= x_127 x_125))) (?v_8 (= x_150 x_137)) (?v_5 (= x_151 x_138)) (?v_6 (= x_152 x_139)) (?v_9 (= x_153 x_140)) (?v_7 (not (<= x_140 x_138))) (?v_3 (= x_163 x_150)) (?v_0 (= x_164 x_151)) (?v_1 (= x_165 x_152)) (?v_4 (= x_166 x_153)) (?v_2 (not (<= x_153 x_151)))) (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (not (= x_2 x_1)) (= x_176 (select x_13 x_1))) (= x_177 (select x_13 x_2))) (or (not (= x_176 3)) (not (= x_177 3)))) (= x_178 (select x_12 x_1))) (= x_179 (select x_12 x_2))) (or (not (= x_178 3)) (not (= x_179 3)))) (= x_180 (select x_11 x_1))) (= x_181 (select x_11 x_2))) (or (not (= x_180 3)) (not (= x_181 3)))) (= x_182 (select x_10 x_1))) (= x_183 (select x_10 x_2))) (or (not (= x_182 3)) (not (= x_183 3)))) (= x_184 (select x_9 x_1))) (= x_185 (select x_9 x_2))) (or (not (= x_184 3)) (not (= x_185 3)))) (= x_186 (select x_8 x_1))) (= x_187 (select x_8 x_2))) (or (not (= x_186 3)) (not (= x_187 3)))) (= x_188 (select x_7 x_1))) (= x_189 (select x_7 x_2))) (or (not (= x_188 3)) (not (= x_189 3)))) (= x_190 (select x_6 x_1))) (= x_191 (select x_6 x_2))) (or (not (= x_190 3)) (not (= x_191 3)))) (= x_192 (select x_5 x_1))) (= x_193 (select x_5 x_2))) (or (not (= x_192 3)) (not (= x_193 3)))) (= x_194 (select x_4 x_1))) (= x_195 (select x_4 x_2))) (or (not (= x_194 3)) (not (= x_195 3)))) (= x_196 (select x_3 x_1))) (= x_197 (select x_3 x_2))) (or (not (= x_196 3)) (not (= x_197 3)))) (= x_198 (select x_0 x_1))) (= x_199 (select x_0 x_2))) (or (not (= x_198 3)) (not (= x_199 3)))) (= x_200 (select x_14 x_15))) (= x_16 x_200)) (= x_201 (select x_17 x_18))) (= x_32 x_201)) (= x_202 (select x_33 x_34))) (= x_45 x_202)) (= x_203 (select x_46 x_47))) (= x_58 x_203)) (= x_204 (select x_59 x_60))) (= x_71 x_204)) (= x_205 (select x_72 x_73))) (= x_84 x_205)) (= x_206 (select x_85 x_86))) (= x_97 x_206)) (= x_207 (select x_98 x_99))) (= x_110 x_207)) (= x_208 (select x_111 x_112))) (= x_123 x_208)) (= x_209 (select x_124 x_125))) (= x_136 x_209)) (= x_210 (select x_137 x_138))) (= x_149 x_210)) (= x_211 (select x_150 x_151))) (= x_162 x_211)) (= x_167 (+ x_154 1))) (= x_212 (select x_13 x_169))) (= x_213 (select x_13 x_172))) (= x_214 (select x_13 x_174))) (or (or (or (and (and (and (and (and (and (and (= x_168 0) (= x_166 (+ x_153 1))) ?v_0) ?v_1) (= x_170 x_169)) (= x_212 1)) (= x_171 (store x_13 x_169 2))) (= x_163 (store x_150 x_153 x_169))) (and (and (and (and (and (and (and (and (and (= x_168 1) ?v_2) ?v_0) ?v_1) ?v_3) ?v_4) (= x_173 x_172)) (= x_213 2)) (= x_162 x_172)) (= x_171 (store x_13 x_172 3)))) (and (and (and (and (and (and (and (and (and (= x_168 2) ?v_2) (= x_164 (+ x_151 1))) ?v_1) ?v_3) ?v_4) (= x_175 x_174)) (= x_214 3)) (or (not (<= x_154 12)) (= x_162 x_174))) (= x_171 (store x_13 x_174 1)))) (and (and (and (and (and (= x_168 3) ?v_3) ?v_0) ?v_1) (= x_171 x_13)) ?v_4))) (= x_154 (+ x_141 1))) (= x_215 (select x_12 x_156))) (= x_216 (select x_12 x_158))) (= x_217 (select x_12 x_160))) (or (or (or (and (and (and (and (and (and (and (= x_155 0) (= x_153 (+ x_140 1))) ?v_5) ?v_6) (= x_157 x_156)) (= x_215 1)) (= x_13 (store x_12 x_156 2))) (= x_150 (store x_137 x_140 x_156))) (and (and (and (and (and (and (and (and (and (= x_155 1) ?v_7) ?v_5) ?v_6) ?v_8) ?v_9) (= x_159 x_158)) (= x_216 2)) (= x_149 x_158)) (= x_13 (store x_12 x_158 3)))) (and (and (and (and (and (and (and (and (and (= x_155 2) ?v_7) (= x_151 (+ x_138 1))) ?v_6) ?v_8) ?v_9) (= x_161 x_160)) (= x_217 3)) (or (not (<= x_141 12)) (= x_149 x_160))) (= x_13 (store x_12 x_160 1)))) (and (and (and (and (and (= x_155 3) ?v_8) ?v_5) ?v_6) (= x_13 x_12)) ?v_9))) (= x_141 (+ x_128 1))) (= x_218 (select x_11 x_143))) (= x_219 (select x_11 x_145))) (= x_220 (select x_11 x_147))) (or (or (or (and (and (and (and (and (and (and (= x_142 0) (= x_140 (+ x_127 1))) ?v_10) ?v_11) (= x_144 x_143)) (= x_218 1)) (= x_12 (store x_11 x_143 2))) (= x_137 (store x_124 x_127 x_143))) (and (and (and (and (and (and (and (and (and (= x_142 1) ?v_12) ?v_10) ?v_11) ?v_13) ?v_14) (= x_146 x_145)) (= x_219 2)) (= x_136 x_145)) (= x_12 (store x_11 x_145 3)))) (and (and (and (and (and (and (and (and (and (= x_142 2) ?v_12) (= x_138 (+ x_125 1))) ?v_11) ?v_13) ?v_14) (= x_148 x_147)) (= x_220 3)) (or (not (<= x_128 12)) (= x_136 x_147))) (= x_12 (store x_11 x_147 1)))) (and (and (and (and (and (= x_142 3) ?v_13) ?v_10) ?v_11) (= x_12 x_11)) ?v_14))) (= x_128 (+ x_115 1))) (= x_221 (select x_10 x_130))) (= x_222 (select x_10 x_132))) (= x_223 (select x_10 x_134))) (or (or (or (and (and (and (and (and (and (and (= x_129 0) (= x_127 (+ x_114 1))) ?v_15) ?v_16) (= x_131 x_130)) (= x_221 1)) (= x_11 (store x_10 x_130 2))) (= x_124 (store x_111 x_114 x_130))) (and (and (and (and (and (and (and (and (and (= x_129 1) ?v_17) ?v_15) ?v_16) ?v_18) ?v_19) (= x_133 x_132)) (= x_222 2)) (= x_123 x_132)) (= x_11 (store x_10 x_132 3)))) (and (and (and (and (and (and (and (and (and (= x_129 2) ?v_17) (= x_125 (+ x_112 1))) ?v_16) ?v_18) ?v_19) (= x_135 x_134)) (= x_223 3)) (or (not (<= x_115 12)) (= x_123 x_134))) (= x_11 (store x_10 x_134 1)))) (and (and (and (and (and (= x_129 3) ?v_18) ?v_15) ?v_16) (= x_11 x_10)) ?v_19))) (= x_115 (+ x_102 1))) (= x_224 (select x_9 x_117))) (= x_225 (select x_9 x_119))) (= x_226 (select x_9 x_121))) (or (or (or (and (and (and (and (and (and (and (= x_116 0) (= x_114 (+ x_101 1))) ?v_20) ?v_21) (= x_118 x_117)) (= x_224 1)) (= x_10 (store x_9 x_117 2))) (= x_111 (store x_98 x_101 x_117))) (and (and (and (and (and (and (and (and (and (= x_116 1) ?v_22) ?v_20) ?v_21) ?v_23) ?v_24) (= x_120 x_119)) (= x_225 2)) (= x_110 x_119)) (= x_10 (store x_9 x_119 3)))) (and (and (and (and (and (and (and (and (and (= x_116 2) ?v_22) (= x_112 (+ x_99 1))) ?v_21) ?v_23) ?v_24) (= x_122 x_121)) (= x_226 3)) (or (not (<= x_102 12)) (= x_110 x_121))) (= x_10 (store x_9 x_121 1)))) (and (and (and (and (and (= x_116 3) ?v_23) ?v_20) ?v_21) (= x_10 x_9)) ?v_24))) (= x_102 (+ x_89 1))) (= x_227 (select x_8 x_104))) (= x_228 (select x_8 x_106))) (= x_229 (select x_8 x_108))) (or (or (or (and (and (and (and (and (and (and (= x_103 0) (= x_101 (+ x_88 1))) ?v_25) ?v_26) (= x_105 x_104)) (= x_227 1)) (= x_9 (store x_8 x_104 2))) (= x_98 (store x_85 x_88 x_104))) (and (and (and (and (and (and (and (and (and (= x_103 1) ?v_27) ?v_25) ?v_26) ?v_28) ?v_29) (= x_107 x_106)) (= x_228 2)) (= x_97 x_106)) (= x_9 (store x_8 x_106 3)))) (and (and (and (and (and (and (and (and (and (= x_103 2) ?v_27) (= x_99 (+ x_86 1))) ?v_26) ?v_28) ?v_29) (= x_109 x_108)) (= x_229 3)) (or (not (<= x_89 12)) (= x_97 x_108))) (= x_9 (store x_8 x_108 1)))) (and (and (and (and (and (= x_103 3) ?v_28) ?v_25) ?v_26) (= x_9 x_8)) ?v_29))) (= x_89 (+ x_76 1))) (= x_230 (select x_7 x_91))) (= x_231 (select x_7 x_93))) (= x_232 (select x_7 x_95))) (or (or (or (and (and (and (and (and (and (and (= x_90 0) (= x_88 (+ x_75 1))) ?v_30) ?v_31) (= x_92 x_91)) (= x_230 1)) (= x_8 (store x_7 x_91 2))) (= x_85 (store x_72 x_75 x_91))) (and (and (and (and (and (and (and (and (and (= x_90 1) ?v_32) ?v_30) ?v_31) ?v_33) ?v_34) (= x_94 x_93)) (= x_231 2)) (= x_84 x_93)) (= x_8 (store x_7 x_93 3)))) (and (and (and (and (and (and (and (and (and (= x_90 2) ?v_32) (= x_86 (+ x_73 1))) ?v_31) ?v_33) ?v_34) (= x_96 x_95)) (= x_232 3)) (or (not (<= x_76 12)) (= x_84 x_95))) (= x_8 (store x_7 x_95 1)))) (and (and (and (and (and (= x_90 3) ?v_33) ?v_30) ?v_31) (= x_8 x_7)) ?v_34))) (= x_76 (+ x_63 1))) (= x_233 (select x_6 x_78))) (= x_234 (select x_6 x_80))) (= x_235 (select x_6 x_82))) (or (or (or (and (and (and (and (and (and (and (= x_77 0) (= x_75 (+ x_62 1))) ?v_35) ?v_36) (= x_79 x_78)) (= x_233 1)) (= x_7 (store x_6 x_78 2))) (= x_72 (store x_59 x_62 x_78))) (and (and (and (and (and (and (and (and (and (= x_77 1) ?v_37) ?v_35) ?v_36) ?v_38) ?v_39) (= x_81 x_80)) (= x_234 2)) (= x_71 x_80)) (= x_7 (store x_6 x_80 3)))) (and (and (and (and (and (and (and (and (and (= x_77 2) ?v_37) (= x_73 (+ x_60 1))) ?v_36) ?v_38) ?v_39) (= x_83 x_82)) (= x_235 3)) (or (not (<= x_63 12)) (= x_71 x_82))) (= x_7 (store x_6 x_82 1)))) (and (and (and (and (and (= x_77 3) ?v_38) ?v_35) ?v_36) (= x_7 x_6)) ?v_39))) (= x_63 (+ x_50 1))) (= x_236 (select x_5 x_65))) (= x_237 (select x_5 x_67))) (= x_238 (select x_5 x_69))) (or (or (or (and (and (and (and (and (and (and (= x_64 0) (= x_62 (+ x_49 1))) ?v_40) ?v_41) (= x_66 x_65)) (= x_236 1)) (= x_6 (store x_5 x_65 2))) (= x_59 (store x_46 x_49 x_65))) (and (and (and (and (and (and (and (and (and (= x_64 1) ?v_42) ?v_40) ?v_41) ?v_43) ?v_44) (= x_68 x_67)) (= x_237 2)) (= x_58 x_67)) (= x_6 (store x_5 x_67 3)))) (and (and (and (and (and (and (and (and (and (= x_64 2) ?v_42) (= x_60 (+ x_47 1))) ?v_41) ?v_43) ?v_44) (= x_70 x_69)) (= x_238 3)) (or (not (<= x_50 12)) (= x_58 x_69))) (= x_6 (store x_5 x_69 1)))) (and (and (and (and (and (= x_64 3) ?v_43) ?v_40) ?v_41) (= x_6 x_5)) ?v_44))) (= x_50 (+ x_37 1))) (= x_239 (select x_4 x_52))) (= x_240 (select x_4 x_54))) (= x_241 (select x_4 x_56))) (or (or (or (and (and (and (and (and (and (and (= x_51 0) (= x_49 (+ x_36 1))) ?v_45) ?v_46) (= x_53 x_52)) (= x_239 1)) (= x_5 (store x_4 x_52 2))) (= x_46 (store x_33 x_36 x_52))) (and (and (and (and (and (and (and (and (and (= x_51 1) ?v_47) ?v_45) ?v_46) ?v_48) ?v_49) (= x_55 x_54)) (= x_240 2)) (= x_45 x_54)) (= x_5 (store x_4 x_54 3)))) (and (and (and (and (and (and (and (and (and (= x_51 2) ?v_47) (= x_47 (+ x_34 1))) ?v_46) ?v_48) ?v_49) (= x_57 x_56)) (= x_241 3)) (or (not (<= x_37 12)) (= x_45 x_56))) (= x_5 (store x_4 x_56 1)))) (and (and (and (and (and (= x_51 3) ?v_48) ?v_45) ?v_46) (= x_5 x_4)) ?v_49))) (= x_37 (+ x_23 1))) (= x_242 (select x_3 x_39))) (= x_243 (select x_3 x_41))) (= x_244 (select x_3 x_43))) (or (or (or (and (and (and (and (and (and (and (= x_38 0) (= x_36 (+ x_21 1))) ?v_50) ?v_51) (= x_40 x_39)) (= x_242 1)) (= x_4 (store x_3 x_39 2))) (= x_33 (store x_17 x_21 x_39))) (and (and (and (and (and (and (and (and (and (= x_38 1) ?v_52) ?v_50) ?v_51) ?v_53) ?v_54) (= x_42 x_41)) (= x_243 2)) (= x_32 x_41)) (= x_4 (store x_3 x_41 3)))) (and (and (and (and (and (and (and (and (and (= x_38 2) ?v_52) (= x_34 (+ x_18 1))) ?v_51) ?v_53) ?v_54) (= x_44 x_43)) (= x_244 3)) (or (not (<= x_23 12)) (= x_32 x_43))) (= x_4 (store x_3 x_43 1)))) (and (and (and (and (and (= x_38 3) ?v_53) ?v_50) ?v_51) (= x_4 x_3)) ?v_54))) (= x_23 (+ x_24 1))) (= x_245 (select x_0 x_26))) (= x_246 (select x_0 x_28))) (= x_247 (select x_0 x_30))) (or (or (or (and (and (and (and (and (and (and (= x_25 0) (= x_21 (+ x_22 1))) ?v_55) ?v_56) (= x_27 x_26)) (= x_245 1)) (= x_3 (store x_0 x_26 2))) (= x_17 (store x_14 x_22 x_26))) (and (and (and (and (and (and (and (and (and (= x_25 1) ?v_57) ?v_55) ?v_56) ?v_58) ?v_59) (= x_29 x_28)) (= x_246 2)) (= x_16 x_28)) (= x_3 (store x_0 x_28 3)))) (and (and (and (and (and (and (and (and (and (= x_25 2) ?v_57) (= x_18 (+ x_15 1))) ?v_56) ?v_58) ?v_59) (= x_31 x_30)) (= x_247 3)) (or (not (<= x_24 12)) (= x_16 x_30))) (= x_3 (store x_0 x_30 1)))) (and (and (and (and (and (= x_25 3) ?v_58) ?v_55) ?v_56) (= x_3 x_0)) ?v_59))) (= x_248 (select x_171 x_1))) (= x_248 3)) (= x_249 (select x_171 x_2))) (= x_249 3))))
(check-sat)
(exit)
