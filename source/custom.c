#include "clips.h"
#include "argacces.h"
#include "constant.h"
#include "factmngr.h"
#include "router.h"
#include "tmpltdef.h"


struct deftemplate* get_ptr(char* deftemplateName){
  struct  deftemplate* df; 
  df = FindDeftemplate(deftemplateName);

  if (!df)
  {
      char retbuff[1024];

      snprintf(
          retbuff,
          sizeof(retbuff),
          "No deftemplate %s found\n",
          deftemplateName
      );
      PrintRouter("wclips", retbuff);
      SetEvaluationError(TRUE);
      return NULL;
  }
  return df;
}

int CountDeftemplates(
    DATA_OBJECT_PTR returnValue)
{

    struct dataObject arg;
    char *deftemplateName;
    struct deftemplate *df;
    struct fact *ft;
    int argCount = RtnArgCount();
    

    if(argCount != 1){
      PrintRouter("error", "Shold be exactly one argument");
      SetEvaluationError(TRUE);
      return -1;
    }

    RtnUnknown(0, &arg);

    switch (arg.type) {

      case STRING:
      case SYMBOL:
        deftemplateName = ValueToString(arg.value);
        df = get_ptr(deftemplateName);
        break;


      case DEFTEMPLATE_PTR:
        df = arg.value;
        break;
    
      default:
        PrintRouter("werror", "Argument should be string of deftemplate name or deftemplate!");
        SetEvaluationError(TRUE);
        return -1;

    }

    if(! df ){
      return -1;
    }


    int count = 0;
    ft = NULL;

    for (ft = (struct fact *) GetNextFact(NULL);
         ft != NULL;
         ft = (struct fact *) GetNextFact(ft))
    {
        if ((void*)ft->whichDeftemplate == (void*)df) {
            count++;
        }
    }
    returnValue->type  = INTEGER;
    returnValue->value = AddLong((long) count);
    return count;
}


