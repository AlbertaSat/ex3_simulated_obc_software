module Components {
    
    # @ A port for carrying a string
    port StringValue(a: string)
    
    @ Interface for deployable items (gpios for burnwires and switches) on SC
    passive component DeployablesInterface {

        # ----------------------------------------------------------------------
        # Ports
        # ----------------------------------------------------------------------
        

        @ Port for sending data to the deployable (toggling a burnwire)  
        sync input port deployableDataOutgoing: StringValue

        @ Port for sending data from the deployable (switch status) to an Fprime component
        output port deployableDataIncoming: StringValue

        # ----------------------------------------------------------------------
        # Commands
        # ----------------------------------------------------------------------
        # Shouldn't issue any commands is it  is just an interface for sending and receiving data 

        # ----------------------------------------------------------------------
        # Events
        # ----------------------------------------------------------------------
        @ Log recevied data over event - log of system activity
        event receivedDeployableData(receivedDeployableData: string) \
            severity activity low \
            format "Received Deployable Data: {}"

        @ Log send data over event - log of system activity
        event sentDeployableData(sentDeployableData: string) \
            severity activity low \
            format "Sent Deployable Data: {}"

        @ Log socket open success 
        event socketOpenSuccess() \
            severity activity low \
            format "Deployable interface socket open success"
        
        @ Log socket open failure 
        event socketOpenFailure(failureMessage: string) \
            severity warning high \
            format "Deployable interface socket open failure: {}"

        @ Log socket send failure 
        event socketSendFailure(failureMessage: string) \
            severity warning high \
            format "Deployable interface socket send failure: {}"

        @ Log socket read failure 
        event socketReadFailure(failureMessage: string) \
            severity warning high \
            format "Deployable interface socket read failure: {}"

        @ Log socket closed
        event socketClosed() \
            severity activity low \
            format "Deployable interface socket closed"


        # ----------------------------------------------------------------------
        # Parameters
        # ----------------------------------------------------------------------
        param TCPPortNumber: U32 default 1811


        ###############################################################################
        # Standard AC Ports: Required for Channels, Events, Commands, and Parameters  #
        ###############################################################################
        @ Port for requesting the current time
        time get port timeCaller

        @ Port for sending command registrations
        command reg port cmdRegOut

        @ Port for receiving commands
        command recv port cmdIn

        @ Port for sending command responses
        command resp port cmdResponseOut

        @ Port for sending textual representation of events
        text event port logTextOut

        @ Port for sending events to downlink
        event port logOut

        @ Port for sending telemetry channels to downlink
        telemetry port tlmOut

        @ Port to return the value of a parameter
        param get port prmGetOut

        @Port to set the value of a parameter
        param set port prmSetOut

    }
}