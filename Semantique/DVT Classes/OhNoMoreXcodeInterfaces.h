//
//  OhNoMoreXcodeInterfaces.h
//  BBUCodingInColorPlugin
//
//  Created by Boris Bügling on 02.02.14.
//  Copyright (c) 2014 Boris Bügling. All rights reserved.
//

#import <AppKit/AppKit.h>

@interface DVTSourceModelItem : NSObject

@property NSArray* children;
@property short nodeType;
@property NSRange range;

-(BOOL)isIdentifier;

@end

#pragma mark -

@interface DVTSourceModel : NSObject
{
    struct _NSRange _dirtyRange;
    long long _batchDelta;
    DVTSourceModelItem *_sourceItems;
    BOOL _isDoingBatchEdit;
}

+ (id)editorResponsivenessPerformanceLogAspect;
+ (void)initialize;
@property BOOL isDoingBatchEdit; // @synthesize isDoingBatchEdit=_isDoingBatchEdit;
@property long long batchDelta; // @synthesize batchDelta=_batchDelta;
@property struct _NSRange dirtyRange; // @synthesize dirtyRange=_dirtyRange;
@property(retain) DVTSourceModelItem *sourceItems; // @synthesize sourceItems=_sourceItems;
- (id)objCMethodNameForItem:(id)arg1 nameRanges:(id *)arg2;
- (BOOL)isItemDictionaryLiteral:(id)arg1;
- (BOOL)isItemObjectLiteral:(id)arg1;
- (BOOL)isItemForStatement:(id)arg1;
- (BOOL)isItemSemanticBlock:(id)arg1;
- (BOOL)isItemBracketExpression:(id)arg1;
- (BOOL)isItemAngleExpression:(id)arg1;
- (BOOL)isItemParenExpression:(id)arg1;
- (BOOL)isPostfixExpressionAtLocation:(unsigned long long)arg1;
- (BOOL)isInTokenizableCodeAtLocation:(unsigned long long)arg1;
- (BOOL)isInPlainCodeAtLocation:(unsigned long long)arg1;
- (BOOL)isInKeywordAtLocation:(unsigned long long)arg1;
- (BOOL)isIncompletionPlaceholderAtLocation:(unsigned long long)arg1;
- (BOOL)isInNumberConstantAtLocation:(unsigned long long)arg1;
- (BOOL)isInCharacterConstantAtLocation:(unsigned long long)arg1;
- (BOOL)isInIdentifierAtLocation:(unsigned long long)arg1;
- (BOOL)isInStringConstantAtLocation:(unsigned long long)arg1;
- (BOOL)isInIncludeStatementAtLocation:(unsigned long long)arg1;
- (BOOL)isInPreprocessorStatementAtLocation:(unsigned long long)arg1;
- (BOOL)isInDocCommentAtLocation:(unsigned long long)arg1;
- (BOOL)isInCommentAtLocation:(unsigned long long)arg1;
- (id)completionPlaceholderItemAtLocation:(unsigned long long)arg1;
- (id)identOrKeywordItemAtLocation:(unsigned long long)arg1;
- (id)objCDeclaratorItemAtLocation:(unsigned long long)arg1;
- (id)numberConstantAtLocation:(unsigned long long)arg1;
- (id)characterConstantAtLocation:(unsigned long long)arg1;
- (id)stringConstantAtLocation:(unsigned long long)arg1;
- (id)moduleImportStatementAtLocation:(unsigned long long)arg1;
- (id)includeStatementAtLocation:(unsigned long long)arg1;
- (id)preprocessorStatementAtLocation:(unsigned long long)arg1;
- (id)docCommentAtLocation:(unsigned long long)arg1;
- (id)commentAtLocation:(unsigned long long)arg1;
- (id)placeholderItemsFromItem:(id)arg1;
- (id)identifierItemsFromItem:(id)arg1;
- (id)commentBlockItems;
- (id)functionsAndMethodItems;
- (id)classItems;
- (void)addBlockItemsInTypeList:(long long *)arg1 fromItem:(id)arg2 toArray:(id)arg3;
- (void)addIdentifierItemsFromItem:(id)arg1 toArray:(id)arg2;
- (void)addItemsInTypeList:(long long *)arg1 fromItem:(id)arg2 toArray:(id)arg3;
- (id)functionOrMethodDefinitionAtLocation:(unsigned long long)arg1;
- (id)functionOrMethodAtLocation:(unsigned long long)arg1;
- (id)interfaceDeclarationAtLocation:(unsigned long long)arg1;
- (id)typeDeclarationAtLocation:(unsigned long long)arg1;
- (id)classAtLocation:(unsigned long long)arg1;
- (id)itemNameAtLocation:(unsigned long long)arg1 inTypeList:(long long *)arg2 nameRanges:(id *)arg3 scopeRange:(struct _NSRange *)arg4;
- (id)nameOfItem:(id)arg1 nameRanges:(id *)arg2 scopeRange:(struct _NSRange *)arg3;
- (void)enumerateIdentifierItemsInRange:(struct _NSRange)arg1 usingBlock:(id)arg2;
- (id)itemAtLocation:(unsigned long long)arg1 ofType:(id)arg2;
- (id)itemAtLocation:(unsigned long long)arg1 inTypeList:(long long *)arg2;
- (long long *)typeListForSpecNames:(id)arg1;
- (id)builtUpNameForItem:(id)arg1 nameRanges:(id *)arg2;
- (id)_builtUpNameForItem:(id)arg1 mutableNameRanges:(id)arg2;
- (id)_builtUpNameForSubTree:(id)arg1 mutableNameRanges:(id)arg2;
- (id)objectLiteralItemAtLocation:(unsigned long long)arg1;
- (id)parenItemAtLocation:(unsigned long long)arg1;
- (id)parenLikeItemAtLocation:(unsigned long long)arg1;
- (id)foldableBlockItemForLocation:(unsigned long long)arg1;
- (id)foldableBlockItemForLineAtLocation:(unsigned long long)arg1;
- (id)blockItemAtLocation:(unsigned long long)arg1;
- (long long)indentForItem:(id)arg1;
- (id)adjoiningItemAtLocation:(unsigned long long)arg1;
- (id)enclosingItemAtLocation:(unsigned long long)arg1;
- (id)_topLevelSourceItem;
- (void)parse;
- (void)doingBatchEdit:(BOOL)arg1;
- (void)dirtyRange:(struct _NSRange)arg1 changeInLength:(long long)arg2;
- (id)initWithSourceBufferProvider:(id)arg1;

@end

#pragma mark -

@interface DVTSourceTextView : NSTextView

-(void)_commonInitDVTSourceTextView;

@end

#pragma mark -

@interface DVTTextStorage : NSTextStorage

@property DVTSourceModel* sourceModel;

-(NSColor*)colorAtCharacterIndex:(unsigned long long)charIndex effectiveRange:(NSRangePointer)range context:(id)context;
-(void)fixSyntaxColoringInRange:(NSRange)range;
-(short)nodeTypeAtCharacterIndex:(unsigned long long)charIndex effectiveRange:(NSRangePointer)range context:(id)context;
// FIXME: Workaround for NSObject+YOLO buggyness
-(NSColor*)yl_colorAtCharacterIndex:(unsigned long long)charIndex effectiveRange:(NSRangePointer)range context:(id)context;

@end
