#ifndef _SPI_H
#define _SPI_H

#include <cspi/spi-impl.h>
/*
 * Definitions for AccessibleRole, AccessibleState,
 * AccessibleEvent, and event listeners.
 */
#include <cspi/spi-roletypes.h>
#include <cspi/spi-statetypes.h>
#include <cspi/spi-listener.h>

/*
 * Auxiliary typedefs and mask definitions
 */
#include <libspi/keymasks.h>

#ifdef  __cplusplus
extern "C" {
#endif

/*
 * Enumerated type for text boundary types
 */
typedef enum
{
  SPI_TEXT_BOUNDARY_CHAR,
  SPI_TEXT_BOUNDARY_CURSOR_POS,
  SPI_TEXT_BOUNDARY_WORD_START,
  SPI_TEXT_BOUNDARY_WORD_END,
  SPI_TEXT_BOUNDARY_SENTENCE_START,
  SPI_TEXT_BOUNDARY_SENTENCE_END,
  SPI_TEXT_BOUNDARY_LINE_START,
  SPI_TEXT_BOUNDARY_LINE_END,
  SPI_TEXT_BOUNDARY_ATTRIBUTE_RANGE
} AccessibleTextBoundaryType;

/*
 *
 * Enumerated type for relation types
 *
 */

typedef enum
{
  SPI_RELATION_NULL,
  SPI_RELATION_LABEL_FOR,
  SPI_RELATION_LABELED_BY,
  SPI_RELATION_CONTROLLER_FOR,
  SPI_RELATION_CONTROLLED_BY,
  SPI_RELATION_MEMBER_OF,
  SPI_RELATION_NODE_CHILD_OF,
  SPI_RELATION_EXTENDED,
  SPI_RELATION_LAST_DEFINED
} AccessibleRelationType;


/* don't change the order of these ! */
typedef enum {
  SPI_COORD_TYPE_SCREEN,
  SPI_COORD_TYPE_WINDOW
} AccessibleCoordType;

typedef enum {
  SPI_KEY_PRESS,
  SPI_KEY_RELEASE, 
  SPI_KEY_PRESSRELEASE,
  SPI_KEY_SYM,
  SPI_KEY_STRING
} AccessibleKeySynthType;

typedef enum {
  SPI_KEYLISTENER_NOSYNC = 0,
  SPI_KEYLISTENER_SYNCHRONOUS = 1,
  SPI_KEYLISTENER_CANCONSUME = 2,
  SPI_KEYLISTENER_ALL_WINDOWS = 4
} AccessibleKeyListenerSyncType;

typedef unsigned long AccessibleKeyEventMask;

/**
 * AccessibleComponentLayer:
 * @SPI_LAYER_INVALID: The layer cannot be determined or is somehow undefined.
 * @SPI_LAYER_BACKGROUND: Component belongs to the destop background.
 * @SPI_LAYER_CANVAS: Component is a canvas backdrop or drawing area.
 * @SPI_LAYER_WIDGET: Component is a 'normal' widget.
 * @SPI_LAYER_MDI: Component is drawn in the MDI layer and may have valid
 *                          Z-information relative to other MDI-layer components.
 * @SPI_LAYER_POPUP: Component is in the popup layer, above other widgets and
 *                          MDI components.
 * @SPI_LAYER_OVERLAY: Component is in the overlay plane - this value is reserved
 *                          for future use.
 * @SPI_LAYER_LAST_DEFINED: Used to determine the last valid value in the enum,
 *                          should not be encountered.	
 **/
typedef enum {
    SPI_LAYER_INVALID,
    SPI_LAYER_BACKGROUND,
    SPI_LAYER_CANVAS,
    SPI_LAYER_WIDGET,
    SPI_LAYER_MDI,
    SPI_LAYER_POPUP,
    SPI_LAYER_OVERLAY,
    SPI_LAYER_LAST_DEFINED	
} AccessibleComponentLayer;


/**
 * AccessibleKeySet:
 * @keysyms:
 * @keycodes:
 * @len:
 *
 * Structure containing identifying information about a set of keycode or
 *        keysyms.
 **/
typedef struct _AccessibleKeySet
{
  unsigned long  *keysyms;
  unsigned short *keycodes;
  char          **keystrings;
  short           len;
} AccessibleKeySet;

/**
 * SPI_KEYSET_ALL_KEYS:
 * @SPI_KEYSET_ALL_KEYS: A special value for an AccessibleKeySet type, which tacitly
 *                       includes all keycodes and keyvals for the specified modifier set.
 **/
#define SPI_KEYSET_ALL_KEYS NULL

typedef unsigned long AccessibleKeyMaskType;


/* Basic SPI initialization and event loop function prototypes */

int              SPI_init         (void);
void             SPI_event_main   (void);
void             SPI_event_quit   (void);
SPIBoolean       SPI_eventIsReady (void);
AccessibleEvent *SPI_nextEvent    (SPIBoolean waitForEvent);
int              SPI_exit         (void);

/* Event Listener creation and support.  */

void                      SPI_freeAccessibleKeySet (
	                                           AccessibleKeySet         *keyset);
AccessibleKeySet        * SPI_createAccessibleKeySet (
                                         	   int                       len,
						   const char               *keysyms,
						   short                    *keycodes,
						   const char              **keystrings);
AccessibleEventListener * SPI_createAccessibleEventListener (
	                                           AccessibleEventListenerCB callback,
						   void                     *user_data);
SPIBoolean                AccessibleEventListener_addCallback (
	                                           AccessibleEventListener  *listener,
						   AccessibleEventListenerCB callback,
						   void                     *user_data);
SPIBoolean                AccessibleEventListener_removeCallback (
	                                           AccessibleEventListener  *listener,
						   AccessibleEventListenerCB callback);
void                      AccessibleEventListener_unref (
	                                           AccessibleEventListener  *listener);

/* Keystroke Listener creation and support.  */

AccessibleKeystrokeListener * SPI_createAccessibleKeystrokeListener (
	                                AccessibleKeystrokeListenerCB callback,
					void                         *user_data);
SPIBoolean                    AccessibleKeystrokeListener_addCallback (
	                                AccessibleKeystrokeListener  *listener,
					AccessibleKeystrokeListenerCB callback,
					void                         *user_data);
SPIBoolean                    AccessibleKeystrokeListener_removeCallback (
	                                AccessibleKeystrokeListener *listener,
					AccessibleKeystrokeListenerCB callback);
void                          AccessibleKeystrokeListener_unref (
	                                AccessibleKeystrokeListener *listener);

/* Global functions serviced by the registry */

SPIBoolean SPI_registerGlobalEventListener           (
	                               AccessibleEventListener *listener,
				       const char              *eventType);
SPIBoolean SPI_deregisterGlobalEventListener         (
	                               AccessibleEventListener *listener,
				       const char              *eventType);
SPIBoolean SPI_deregisterGlobalEventListenerAll      (
	                               AccessibleEventListener *listener);
SPIBoolean SPI_registerAccessibleKeystrokeListener   (
                                       AccessibleKeystrokeListener *listener,
				       AccessibleKeySet             *keys,
				       AccessibleKeyMaskType         modmask,
				       AccessibleKeyEventMask        eventmask,
				       AccessibleKeyListenerSyncType sync_type);
SPIBoolean SPI_deregisterAccessibleKeystrokeListener (
	                               AccessibleKeystrokeListener *listener,
				       AccessibleKeyMaskType        modmask);

int         SPI_getDesktopCount                  (void);
Accessible *SPI_getDesktop                       (int i);
int         SPI_getDesktopList                   (Accessible ***desktop_list);
void        SPI_freeDesktopList                  (Accessible  **desktop_list);

SPIBoolean  SPI_generateKeyboardEvent            (long int                    keyval,
						  char                       *keystring,
						  AccessibleKeySynthType      synth_type);

SPIBoolean  SPI_generateMouseEvent               (long int x, long int y, char *name);

/* Accessible function prototypes  */

void                 Accessible_ref              (Accessible *obj);
void                 Accessible_unref            (Accessible *obj);
char *               Accessible_getName          (Accessible *obj);
char *               Accessible_getDescription   (Accessible *obj);
Accessible *         Accessible_getParent        (Accessible *obj);
long                 Accessible_getChildCount    (Accessible *obj);
Accessible *         Accessible_getChildAtIndex  (Accessible *obj,
						  long int    childIndex);
long                 Accessible_getIndexInParent (Accessible *obj);
AccessibleRelation **Accessible_getRelationSet   (Accessible *obj);
AccessibleRole       Accessible_getRole          (Accessible *obj);
char *               Accessible_getRoleName      (Accessible *obj);
AccessibleStateSet * Accessible_getStateSet      (Accessible *obj);

/* Interface query methods */

SPIBoolean Accessible_isAction            (Accessible *obj);
SPIBoolean Accessible_isApplication       (Accessible *obj);
SPIBoolean Accessible_isComponent         (Accessible *obj);
SPIBoolean Accessible_isEditableText      (Accessible *obj);
SPIBoolean Accessible_isHypertext         (Accessible *obj);
SPIBoolean Accessible_isImage             (Accessible *obj);
SPIBoolean Accessible_isSelection         (Accessible *obj);
SPIBoolean Accessible_isStreamableContent (Accessible *obj);
SPIBoolean Accessible_isTable             (Accessible *obj);
SPIBoolean Accessible_isText              (Accessible *obj);
SPIBoolean Accessible_isValue             (Accessible *obj);

AccessibleAction *            Accessible_getAction            (Accessible *obj);
AccessibleApplication *       Accessible_getApplication       (Accessible *obj);
AccessibleComponent *         Accessible_getComponent         (Accessible *obj);
AccessibleEditableText *      Accessible_getEditableText      (Accessible *obj);
AccessibleHypertext *         Accessible_getHypertext         (Accessible *obj);
AccessibleImage *             Accessible_getImage             (Accessible *obj);
AccessibleSelection *         Accessible_getSelection         (Accessible *obj);
AccessibleStreamableContent * Accessible_getStreamableContent (Accessible *obj);
AccessibleTable *             Accessible_getTable             (Accessible *obj);
AccessibleText *              Accessible_getText              (Accessible *obj);
AccessibleValue *             Accessible_getValue             (Accessible *obj);
AccessibleUnknown *           Accessible_queryInterface       (Accessible *obj,
					           const char *interface_name);

/* AccessibleAction function prototypes  */

void       AccessibleAction_ref            (AccessibleAction *obj);
void       AccessibleAction_unref          (AccessibleAction *obj);
long       AccessibleAction_getNActions    (AccessibleAction *obj);
char      *AccessibleAction_getName        (AccessibleAction *obj,
					    long int          i);
char      *AccessibleAction_getDescription (AccessibleAction *obj,
					    long int          i);
SPIBoolean AccessibleAction_doAction       (AccessibleAction *obj,
					    long int          i);
char      *AccessibleAction_getKeyBinding  (AccessibleAction *obj,
					    long int          i);

/* AccessibleApplication function prototypes  */

void       AccessibleApplication_ref            (AccessibleApplication *obj);
void       AccessibleApplication_unref          (AccessibleApplication *obj);
char      *AccessibleApplication_getToolkitName (AccessibleApplication *obj);
char      *AccessibleApplication_getVersion     (AccessibleApplication *obj);
long       AccessibleApplication_getID          (AccessibleApplication *obj);
SPIBoolean AccessibleApplication_pause          (AccessibleApplication *obj);
SPIBoolean AccessibleApplication_resume         (AccessibleApplication *obj);

/* AccessibleComponent function prototypes */

void        AccessibleComponent_ref         (AccessibleComponent *obj);
void        AccessibleComponent_unref       (AccessibleComponent *obj);
SPIBoolean  AccessibleComponent_contains    (AccessibleComponent *obj,
					     long int             x,
					     long int             y,
					     AccessibleCoordType  ctype);
Accessible *AccessibleComponent_getAccessibleAtPoint (
                                             AccessibleComponent *obj,
					     long int             x,
					     long int             y,
					     AccessibleCoordType  ctype);
void        AccessibleComponent_getExtents  (AccessibleComponent *obj,
					     long int            *x,
					     long int            *y,
					     long int            *width,
					     long int            *height,
					     AccessibleCoordType  ctype);
void        AccessibleComponent_getPosition (AccessibleComponent *obj,
					     long int            *x,
					     long int            *y,
					     AccessibleCoordType  ctype);
void        AccessibleComponent_getSize     (AccessibleComponent *obj,
					     long int            *width,
					     long int            *height);
AccessibleComponentLayer
            AccessibleComponent_getLayer    (AccessibleComponent *obj);
void        AccessibleComponent_grabFocus   (AccessibleComponent *obj);
short       AccessibleComponent_getMDIZOrder(AccessibleComponent *obj);

/* AccessibleEditableText function prototypes  */

void
AccessibleEditableText_ref (AccessibleEditableText *obj);

void
AccessibleEditableText_unref (AccessibleEditableText *obj);

SPIBoolean
AccessibleEditableText_setAttributes (AccessibleEditableText *obj,
				      const char *attributes,
				      long int startOffset,
				      long int endOffset);

SPIBoolean
AccessibleEditableText_setTextContents (AccessibleEditableText *obj,
                                        const char *newContents);

SPIBoolean
AccessibleEditableText_insertText (AccessibleEditableText *obj,
                                   long int position,
                                   const char *text,
                                   long int length);

SPIBoolean
AccessibleEditableText_copyText (AccessibleText *obj,
                                 long int startPos,
                                 long int endPos);

SPIBoolean
AccessibleEditableText_cutText (AccessibleEditableText *obj,
                                long int startPos,
                                long int endPos);

SPIBoolean
AccessibleEditableText_deleteText (AccessibleEditableText *obj,
                                   long int startPos,
                                   long int endPos);

SPIBoolean
AccessibleEditableText_pasteText (AccessibleEditableText *obj,
                                  long int position);

/*
 *
 * AccessibleHyperlink function prototypes
 *
 */
void
AccessibleHyperlink_ref (AccessibleHyperlink *obj);
void
AccessibleHyperlink_unref (AccessibleHyperlink *obj);

long
AccessibleHyperlink_getNAnchors (AccessibleHyperlink *obj);

char *
AccessibleHyperlink_getURI (AccessibleHyperlink *obj,
                            long int i);

Accessible *
AccessibleHyperlink_getObject (AccessibleHyperlink *obj,
                               long int i);

void
AccessibleHyperlink_getIndexRange (AccessibleHyperlink *obj,
                                   long int *startIndex,
                                   long int *endIndex);

SPIBoolean
AccessibleHyperlink_isValid (AccessibleHyperlink *obj);

/*
 *
 * AccessibleHypertext function prototypes
 *
 */

void
AccessibleHypertext_ref (AccessibleHypertext *obj);

void
AccessibleHypertext_unref (AccessibleHypertext *obj);

long
AccessibleHypertext_getNLinks (AccessibleHypertext *obj);

AccessibleHyperlink *
AccessibleHypertext_getLink (AccessibleHypertext *obj,
                             long int linkIndex);

long
AccessibleHypertext_getLinkIndex (AccessibleHypertext *obj,
                                  long int characterOffset);

/*
 *
 * AccessibleImage function prototypes
 *
 */

void
AccessibleImage_ref (AccessibleImage *obj);

void
AccessibleImage_unref (AccessibleImage *obj);

char *
AccessibleImage_getImageDescription (AccessibleImage *obj);

void
AccessibleImage_getImageSize (AccessibleImage *obj,
                              long int *width,
                              long int *height);

void
AccessibleImage_getImagePosition (AccessibleImage *obj,
                                  long int *x,
                                  long int *y,
                                  AccessibleCoordType ctype);

void
AccessibleImage_getImageExtents (AccessibleImage *obj,
				 long int *x,
				 long int *y,
				 long int *width,
				 long int *height,
				 AccessibleCoordType ctype);
/*
 *
 * AccessibleRelation function prototypes
 *
 */

void AccessibleRelation_ref   (AccessibleRelation *obj);
void AccessibleRelation_unref (AccessibleRelation *obj);

AccessibleRelationType
AccessibleRelation_getRelationType (AccessibleRelation *obj);

int
AccessibleRelation_getNTargets (AccessibleRelation *obj);

Accessible *
AccessibleRelation_getTarget (AccessibleRelation *obj, int i);


/*
 *
 * AccessibleSelection function prototypes
 *
 */

void AccessibleSelection_ref   (AccessibleSelection *obj);
void AccessibleSelection_unref (AccessibleSelection *obj);

long
AccessibleSelection_getNSelectedChildren (AccessibleSelection *obj);

Accessible *
AccessibleSelection_getSelectedChild (AccessibleSelection *obj,
                                      long int selectedChildIndex);

SPIBoolean
AccessibleSelection_selectChild (AccessibleSelection *obj,
                                 long int childIndex);

SPIBoolean
AccessibleSelection_deselectSelectedChild (AccessibleSelection *obj,
                                           long int selectedChildIndex);

SPIBoolean
AccessibleSelection_isChildSelected (AccessibleSelection *obj,
                                     long int childIndex);

SPIBoolean
AccessibleSelection_selectAll (AccessibleSelection *obj);

void
AccessibleSelection_clearSelection (AccessibleSelection *obj);


/*
 *
 * AccessibleStateSet function prototypes
 *
 */

void AccessibleStateSet_ref   (AccessibleStateSet *obj);
void AccessibleStateSet_unref (AccessibleStateSet *obj);

SPIBoolean
AccessibleStateSet_contains (AccessibleStateSet *obj,
                             AccessibleState state);

void
AccessibleStateSet_add (AccessibleStateSet *obj,
                        AccessibleState state);

void
AccessibleStateSet_remove (AccessibleStateSet *obj,
                           AccessibleState state);

SPIBoolean
AccessibleStateSet_equals (AccessibleStateSet *obj,
                           AccessibleStateSet *obj2);

AccessibleStateSet *
AccessibleStateSet_compare (AccessibleStateSet *obj,
                            AccessibleStateSet *obj2);

SPIBoolean
AccessibleStateSet_isEmpty (AccessibleStateSet *obj);

void
AccessibleStreamableContent_ref (AccessibleStreamableContent *obj);
void
AccessibleStreamableContent_unref (AccessibleStreamableContent *obj);
char **
AccessibleStreamableContent_getContentTypes (AccessibleStreamableContent *obj);
SPIBoolean
AccessibleStreamableContent_open (AccessibleStreamableContent *obj,
				  const char *content_type);
SPIBoolean
AccessibleStreamableContent_seek (AccessibleStreamableContent *obj,
				  long int offset);
SPIBoolean
AccessibleStreamableContent_read (AccessibleStreamableContent *obj,
				  void *buff,
				  long int nbytes,
				  unsigned int read_type);
/*
 *
 * AccessibleTable function prototypes
 *
 */

void AccessibleTable_ref   (AccessibleTable *obj);
void AccessibleTable_unref (AccessibleTable *obj);

Accessible *
AccessibleTable_getCaption (AccessibleTable *obj);

Accessible *
AccessibleTable_getSummary (AccessibleTable *obj);

long
AccessibleTable_getNRows (AccessibleTable *obj);

long
AccessibleTable_getNColumns (AccessibleTable *obj);

Accessible *
AccessibleTable_getAccessibleAt (AccessibleTable *obj,
                                 long int row,
                                 long int column);

long
AccessibleTable_getIndexAt (AccessibleTable *obj,
                            long int row,
                            long int column);

long
AccessibleTable_getRowAtIndex (AccessibleTable *obj,
                               long int index);

long
AccessibleTable_getColumnAtIndex (AccessibleTable *obj,
                                  long int index);

char *
AccessibleTable_getRowDescription (AccessibleTable *obj,
				   long int row);

char *
AccessibleTable_getColumnDescription (AccessibleTable *obj,
				      long int column);

long
AccessibleTable_getRowExtentAt (AccessibleTable *obj,
                                long int row,
                                long int column);

long
AccessibleTable_getColumnExtentAt (AccessibleTable *obj,
                                   long int row,
                                   long int column);

Accessible *
AccessibleTable_getRowHeader (AccessibleTable *obj,
			      long int row);

Accessible *
AccessibleTable_getColumnHeader (AccessibleTable *obj,
				 long int column);

long
AccessibleTable_getNSelectedRows (AccessibleTable *obj);

long
AccessibleTable_getSelectedRows (AccessibleTable *obj,
                                 long int **selectedRows);

long
AccessibleTable_getNSelectedColumns (AccessibleTable *obj);

long
AccessibleTable_getSelectedColumns (AccessibleTable *obj,
                                    long int **selectedColumns);

SPIBoolean
AccessibleTable_isRowSelected (AccessibleTable *obj,
                               long int row);

SPIBoolean
AccessibleTable_isColumnSelected (AccessibleTable *obj,
                                  long int column);

SPIBoolean
AccessibleTable_isSelected (AccessibleTable *obj,
                            long int row,
                            long int column);

/*
 *
 * AccessibleText function prototypes
 *
 */

void AccessibleText_ref   (AccessibleText *obj);
void AccessibleText_unref (AccessibleText *obj);

long
AccessibleText_getCharacterCount (AccessibleText *obj);

char *
AccessibleText_getText (AccessibleText *obj,
                        long int startOffset,
                        long int endOffset);

long
AccessibleText_getCaretOffset (AccessibleText *obj);

char *
AccessibleText_getAttributes (AccessibleText *obj,
				 long int offset,
				 long int *startOffset,
				 long int *endOffset);


SPIBoolean
AccessibleText_setCaretOffset (AccessibleText *obj,
                               long int newOffset);

char *
AccessibleText_getTextBeforeOffset (AccessibleText *obj,
                                    long int offset,
                                    AccessibleTextBoundaryType type,
				    long int *startOffset,
				    long int *endOffset);

char *
AccessibleText_getTextAtOffset (AccessibleText *obj,
				long int offset,
				AccessibleTextBoundaryType type,
				long int *startOffset,
				long int *endOffset);

char *
AccessibleText_getTextAfterOffset (AccessibleText *obj,
				   long int offset,
				   AccessibleTextBoundaryType type,
				   long int *startOffset,
				   long int *endOffset);

unsigned long
AccessibleText_getCharacterAtOffset (AccessibleText *obj,
                                     long int offset);

void
AccessibleText_getCharacterExtents (AccessibleText *obj,
                                    long int offset,
                                    long int *x,
                                    long int *y,
                                    long int *width,
                                    long int *height,
				    AccessibleCoordType type);

long
AccessibleText_getOffsetAtPoint (AccessibleText *obj,
                                 long int x,
                                 long int y,
				 AccessibleCoordType type);

long
AccessibleText_getNSelections (AccessibleText *obj);

void
AccessibleText_getSelection (AccessibleText *obj,
			     long int selectionNum,
			     long int *startOffset,
			     long int *endOffset);


SPIBoolean
AccessibleText_addSelection (AccessibleText *obj,
			     long int startOffset,
			     long int endOffset);

SPIBoolean
AccessibleText_removeSelection (AccessibleText *obj,
				long int selectionNum);

SPIBoolean
AccessibleText_setSelection (AccessibleText *obj,
			     long int selectionNum,
			     long int startOffset,
			     long int endOffset);

/* AccessibleValue Function Prototypes:  */

void       AccessibleValue_ref             (AccessibleValue *obj);
void       AccessibleValue_unref           (AccessibleValue *obj);
double     AccessibleValue_getMinimumValue (AccessibleValue *obj);
double     AccessibleValue_getCurrentValue (AccessibleValue *obj);
double     AccessibleValue_getMaximumValue (AccessibleValue *obj);
SPIBoolean AccessibleValue_setCurrentValue (AccessibleValue *obj,
					    double           newValue);

/* Misc methods */
void SPI_freeString (char *s);

#ifdef  __cplusplus
}
#endif

#endif
