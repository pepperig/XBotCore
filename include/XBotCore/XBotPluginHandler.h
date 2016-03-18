/*
   Copyright (C) 2016 Italian Institute of Technology

   Developer:
       Luca Muratore (2016-, luca.muratore@iit.it)
   
*/

/**
 *
 * @author Luca Muratore (2016-, luca.muratore@iit.it)
*/

#ifndef __X_BOT_PLUGIN_HANDLER_H__
#define __X_BOT_PLUGIN_HANDLER_H__

#include <XBotCore/XBotCore.h>

/**
 * @brief TBD
 * 
 */
class XBotPluginHandler : public XBotCore
{
public:
    
    XBotPluginHandler(const char * config_yaml);
    virtual ~XBotPluginHandler();

    virtual bool plugin_handler_init(void) final;
    virtual bool plugin_handler_loop(void) final;

protected:
            


private: 
        
//     bool get_rtt(int joint_id, uint16_t& rtt);

};

#endif //__X_BOT_PLUGIN_HANDLER_H__
