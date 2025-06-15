#ifndef IOBSERVER_H
#define IOBSERVER_H

class DTNotificacion;

class IObserver {
public:
    virtual ~IObserver() {}
    
    virtual void notificar(const DTNotificacion& notif) = 0;
};

#endif